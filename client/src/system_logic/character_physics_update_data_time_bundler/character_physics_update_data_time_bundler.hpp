#ifndef CHARACTER_PHYSICS_UPDATE_DATA_TIME_BUNDLER_HPP
#define CHARACTER_PHYSICS_UPDATE_DATA_TIME_BUNDLER_HPP

#include "../reconciliation_types/reconciliation_types.hpp"
#include "../../utility/logger/logger.hpp"

/**
 * @brief you should be calling get bundle constrained dt, and then the  register cpud in that order for this to run
 * properly
 *
 *
 */
class CharacterPhysicsUpdateDataTimeBundler {
  public:
    unsigned int server_tick_rate = 60;
    double server_dt = 1.0 / 60.0;

  private:
    double bundle_accumulated_dt = 0.0; // how full the current bundle is
    double carry_dt = 0.0;              // leftover dt from previous calls
    bool create_new_bundle_after_next_registration = false;

    CharacterUpdateDataTimeBundle current_bundle;
    // NOTE: mentally there's only ever going to be one bundle to send over, but it's possible if we have an empty tick
    // that we'd send two on the next tick and that's why thisis a vector
    // instead if we synchronize on the size of this ie, only send out when enough time has passed then this can be done
    // cleaner.
    std::vector<CharacterUpdateDataTimeBundle> bundles_since_last_client_to_server_send;

  public:
    // WARN: if we pass reference the returned object may change, so keep this in mind
    const std::vector<CharacterUpdateDataTimeBundle> get_bundles_since_last_client_to_server_send() const {
        std::vector<CharacterUpdateDataTimeBundle> bundles;
        for (const auto bundle : bundles_since_last_client_to_server_send) {
            bundles.push_back(bundle);
        }
        return bundles_since_last_client_to_server_send;
    }

    /**
     * @note When the frequency at which this is called is not an integer multiple of the server send frequency it will
     * cause the last dt to be smaller (think quotient remainder theorem)
     */
    double get_bundle_constrained_dt(double dt) {
        GlobalLogSection _("get_bundle_constrained_dt");

        global_logger->debug("Input dt = {}", dt);
        global_logger->debug("Initial state: carry_dt = {}, bundle_accumulated_dt = {}, server_dt = {}", carry_dt,
                             bundle_accumulated_dt, server_dt);

        // apply carry_dt from previous call
        if (carry_dt != 0) {
            global_logger->debug("Applying carry_dt: {} + {} = {}", dt, carry_dt, dt + carry_dt);
            dt += carry_dt;
            carry_dt = 0;
        }

        double remaining_time_in_current_bundle = server_dt - bundle_accumulated_dt;

        global_logger->debug("Remaining time in current bundle = server_dt ({}) - bundle_accumulated_dt ({}) = {}",
                             server_dt, bundle_accumulated_dt, remaining_time_in_current_bundle);

        bool should_create_new_bundle = dt > remaining_time_in_current_bundle;
        if (should_create_new_bundle) {
            create_new_bundle_after_next_registration = true;
            bundle_accumulated_dt = 0;
            auto usable_dt = remaining_time_in_current_bundle;

            global_logger->debug("dt ({}) > remaining_time_in_current_bundle ({}): creating new bundle", dt,
                                 remaining_time_in_current_bundle);

            global_logger->debug("Usable dt for this bundle = {}", usable_dt);
            global_logger->debug("Carrying leftover dt = dt - usable_dt = {} - {} = {}", dt, usable_dt, dt - usable_dt);

            // bundle_accumulated_dt += usable_dt;
            carry_dt = dt - remaining_time_in_current_bundle;

            global_logger->debug("New state after filling bundle:");
            global_logger->debug("  bundle_accumulated_dt = {}", bundle_accumulated_dt);
            global_logger->debug("  carry_dt = {}", carry_dt);
            global_logger->debug("  current_bundle_is_filled = {}", create_new_bundle_after_next_registration);

            return usable_dt;
        }
        // otherwise we know that dt <= remaining_time_in_current_bundle

        bundle_accumulated_dt += dt;
        auto usable_dt = dt;

        global_logger->debug("dt ({}) fits in the current bundle.", dt);
        global_logger->debug("Updated bundle_accumulated_dt = {}", bundle_accumulated_dt);

        return usable_dt;
    }

    /// @brief the cpud's dt must come from the above function
    void register_cud(IdTaggedCharacterUpdateData id_tagged_character_update_data_with_bundle_constrained_dt) {

        current_bundle.id_tagged_character_update_datas.push_back(
            id_tagged_character_update_data_with_bundle_constrained_dt);

        // when this variables value is set, the above would have been the "next registration"
        if (create_new_bundle_after_next_registration) {
            create_new_bundle();
        }
    }

    void create_new_bundle() {
        bundles_since_last_client_to_server_send.push_back(current_bundle);
        current_bundle.id_tagged_character_update_datas.clear();
        create_new_bundle_after_next_registration = false;
    }

    /// @brief Get all bundles accumulated since last call and clear the storage, the current (incomplete) bundle will
    /// not be in here.
    std::vector<CharacterUpdateDataTimeBundle> take_bundles_since_last_send() {
        std::vector<CharacterUpdateDataTimeBundle> result = std::move(bundles_since_last_client_to_server_send);
        bundles_since_last_client_to_server_send.clear(); // just to be safe, though move already empties it
        return result;
    }
};

#endif // CHARACTER_PHYSICS_UPDATE_DATA_TIME_BUNDLER_HPP
