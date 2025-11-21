#include "create_world.hpp"

std::vector<draw_info::IVPColor> create_world() {

    std::vector<draw_info::IVPColor> objects_to_draw;

    // --- Floor ---
    auto floor = draw_info::IVPColor(vertex_geometry::generate_box(20, 1, 20), colors::aliceblue);
    floor.transform.set_translation_y(-10);
    draw_info::apply_transform(floor);
    objects_to_draw.push_back(floor);

    // --- Roof ---
    auto roof = draw_info::IVPColor(vertex_geometry::generate_box(20, 1, 20), colors::lightgray);
    roof.transform.set_translation_y(10);
    draw_info::apply_transform(roof);
    objects_to_draw.push_back(roof);

    // --- Walls ---
    auto wall_color_1 = colors::lightcoral;
    auto wall_color_2 = colors::lightgreen;

    // Front wall
    auto wall_front = draw_info::IVPColor(vertex_geometry::generate_box(20, 20, 1), wall_color_1);
    wall_front.transform.set_translation_z(-10);
    draw_info::apply_transform(wall_front);
    objects_to_draw.push_back(wall_front);

    // Back wall
    auto wall_back = draw_info::IVPColor(vertex_geometry::generate_box(20, 20, 1), wall_color_1);
    wall_back.transform.set_translation_z(10);
    draw_info::apply_transform(wall_back);
    objects_to_draw.push_back(wall_back);

    // Left wall
    auto wall_left = draw_info::IVPColor(vertex_geometry::generate_box(1, 20, 20), wall_color_2);
    wall_left.transform.set_translation_x(-10);
    draw_info::apply_transform(wall_left);
    objects_to_draw.push_back(wall_left);

    // Right wall
    auto wall_right = draw_info::IVPColor(vertex_geometry::generate_box(1, 20, 20), wall_color_2);
    wall_right.transform.set_translation_x(10);
    draw_info::apply_transform(wall_right);
    objects_to_draw.push_back(wall_right);

    // --- Cones (non-random placement) ---
    auto cone_color = colors::orange;

    // Choose fixed positions — here arranged in a plus shape:
    std::vector<glm::vec2> cone_positions = {
        {-5.0f, 0.0f}, {5.0f, 0.0f}, {0.0f, -5.0f}, {0.0f, 5.0f}, {0.0f, 0.0f} // center cone
    };

    for (auto &pos : cone_positions) {
        auto cone = draw_info::IVPColor(vertex_geometry::generate_cone(16, 2.0f, 1.0f), cone_color);

        cone.transform.set_translation_x(pos.x);
        cone.transform.set_translation_z(pos.y);
        cone.transform.set_translation_y(-9.0f); // sits on the floor

        draw_info::apply_transform(cone);
        objects_to_draw.push_back(cone);
    }

    return objects_to_draw;
}
