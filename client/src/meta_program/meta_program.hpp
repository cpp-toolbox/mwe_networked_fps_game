#ifndef META_PROGRAM_HPP
#define META_PROGRAM_HPP

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <Jolt/Jolt.h>
#include <Jolt/Math/Vec3.h>
#include <Jolt/Jolt.h>
#include <Jolt/Math/Mat44.h>
#include "../networking/packet_types/packet_types.hpp"
#include "../networking/packet_data/packet_data.hpp"
#include "../networking/packet_data/packet_data.hpp"
#include "../sound/sound_types/sound_types.hpp"
#include "../system_logic/data_to_reconstruct_client_game_state_when_firing_on_server/data_to_reconstruct_client_game_state_when_firing_on_server.hpp"
#include "../system_logic/data_to_reconstruct_client_game_state_when_firing_on_server/data_to_reconstruct_client_game_state_when_firing_on_server.hpp"
#include "../system_logic/reconciliation_types/reconciliation_types.hpp"
#include "../system_logic/reconciliation_types/reconciliation_types.hpp"
#include "../system_logic/reconciliation_types/reconciliation_types.hpp"
#include "../system_logic/reconciliation_types/reconciliation_types.hpp"
#include "../system_logic/reconciliation_types/reconciliation_types.hpp"
#include "../system_logic/reconciliation_types/reconciliation_types.hpp"
#include "../system_logic/reconciliation_types/reconciliation_types.hpp"
#include "../system_logic/reconciliation_types/reconciliation_types.hpp"
#include "../system_logic/reconciliation_types/reconciliation_types.hpp"
#include "../system_logic/reconciliation_types/reconciliation_types.hpp"
#include "../system_logic/reconciliation_types/reconciliation_types.hpp"
#include "../system_logic/reconciliation_types/reconciliation_types.hpp"
#include "../system_logic/reconciliation_types/reconciliation_types.hpp"
#include "../networking/packets/packets.hpp"
#include "../networking/packets/packets.hpp"
#include "../networking/packets/packets.hpp"
#include "../networking/packets/packets.hpp"
#include "../networking/packets/packets.hpp"
#include "../networking/packets/packets.hpp"
#include <optional>
#include "../utility/meta_utils/meta_utils.hpp"
#include "../utility/user_input/user_input.hpp"
#include "../utility/lazy_construction/lazy_construction.hpp"

class MetaProgram {
public:
        MetaProgram(std::vector<meta_utils::MetaType> concrete_types) : concrete_types(concrete_types) {
        }

public:
    std::vector<meta_utils::MetaType>  concrete_types;
    std::string char_to_string(const char &v) {
        return std::to_string(v);

    }
    char string_to_char(const std::string &s) {
        return static_cast<char>(s.empty() ? 0 : s[0]);

    }
    std::vector<uint8_t> serialize_char(const char &v) {
        std::vector<uint8_t> buf(sizeof(char));   std::memcpy(buf.data(), &v, sizeof(char));   return buf;

    }
    size_t size_when_serialized_char(const char &v) {
        return sizeof(char);

    }
    char deserialize_char(const std::vector<uint8_t> &buf) {
        char v;   std::memcpy(&v, buf.data(), sizeof(char));   return v;

    }
    std::string int_to_string(const int &v) {
        return std::to_string(v);

    }
    int string_to_int(const std::string &s) {
        return std::stoi(s);

    }
    std::vector<uint8_t> serialize_int(const int &v) {
        std::vector<uint8_t> buf(sizeof(int));   std::memcpy(buf.data(), &v, sizeof(int));   return buf;

    }
    size_t size_when_serialized_int(const int &v) {
        return sizeof(int);

    }
    int deserialize_int(const std::vector<uint8_t> &buf) {
        int v;   std::memcpy(&v, buf.data(), sizeof(int));   return v;

    }
    std::string unsigned_int_to_string(const unsigned int &v) {
        return std::to_string(v);

    }
    unsigned int string_to_unsigned_int(const std::string &s) {
        return static_cast<unsigned int>(std::stoul(s));

    }
    std::vector<uint8_t> serialize_unsigned_int(const unsigned int &v) {
        std::vector<uint8_t> buf(sizeof(unsigned int));   std::memcpy(buf.data(), &v, sizeof(unsigned int));   return buf;

    }
    size_t size_when_serialized_unsigned_int(const unsigned int &v) {
        return sizeof(unsigned int);

    }
    unsigned int deserialize_unsigned_int(const std::vector<uint8_t> &buf) {
        unsigned int v;   std::memcpy(&v, buf.data(), sizeof(unsigned int));   return v;

    }
    std::string uint8_t_to_string(const uint8_t &v) {
        return std::to_string(v);

    }
    uint8_t string_to_uint8_t(const std::string &s) {
        return static_cast<uint8_t>(std::stoul(s));

    }
    std::vector<uint8_t> serialize_uint8_t(const uint8_t &v) {
        std::vector<uint8_t> buf(sizeof(uint8_t));   std::memcpy(buf.data(), &v, sizeof(uint8_t));   return buf;

    }
    size_t size_when_serialized_uint8_t(const uint8_t &v) {
        return sizeof(uint8_t);

    }
    uint8_t deserialize_uint8_t(const std::vector<uint8_t> &buf) {
        uint8_t v;   std::memcpy(&v, buf.data(), sizeof(uint8_t));   return v;

    }
    std::string uint32_t_to_string(const uint32_t &v) {
        return std::to_string(v);

    }
    uint32_t string_to_uint32_t(const std::string &s) {
        return static_cast<uint32_t>(std::stoul(s));

    }
    std::vector<uint8_t> serialize_uint32_t(const uint32_t &v) {
        std::vector<uint8_t> buf(sizeof(uint32_t));   std::memcpy(buf.data(), &v, sizeof(uint32_t));   return buf;

    }
    size_t size_when_serialized_uint32_t(const uint32_t &v) {
        return sizeof(uint32_t);

    }
    uint32_t deserialize_uint32_t(const std::vector<uint8_t> &buf) {
        uint32_t v;   std::memcpy(&v, buf.data(), sizeof(uint32_t));   return v;

    }
    std::string size_t_to_string(const size_t &v) {
        return std::to_string(v);

    }
    size_t string_to_size_t(const std::string &s) {
        return static_cast<size_t>(std::stoull(s));

    }
    std::vector<uint8_t> serialize_size_t(const size_t &v) {
        std::vector<uint8_t> buf(sizeof(size_t));   std::memcpy(buf.data(), &v, sizeof(size_t));   return buf;

    }
    size_t size_when_serialized_size_t(const size_t &v) {
        return sizeof(size_t);

    }
    size_t deserialize_size_t(const std::vector<uint8_t> &buf) {
        size_t v;   std::memcpy(&v, buf.data(), sizeof(size_t));   return v;

    }
    std::string float_to_string(const float &v) {
        std::ostringstream oss;  oss << std::setprecision(std::numeric_limits<float>::max_digits10) << v;  return oss.str();

    }
    float string_to_float(const std::string &s) {
        return std::stof(s);

    }
    std::vector<uint8_t> serialize_float(const float &v) {
        std::vector<uint8_t> buf(sizeof(float));   std::memcpy(buf.data(), &v, sizeof(float));   return buf;

    }
    size_t size_when_serialized_float(const float &v) {
        return sizeof(float);

    }
    float deserialize_float(const std::vector<uint8_t> &buf) {
        float v;   std::memcpy(&v, buf.data(), sizeof(float));   return v;

    }
    std::string double_to_string(const double &v) {
        std::ostringstream oss;  oss << std::setprecision(std::numeric_limits<double>::max_digits10) << v;  return oss.str();

    }
    double string_to_double(const std::string &s) {
        return std::stod(s);

    }
    std::vector<uint8_t> serialize_double(const double &v) {
        std::vector<uint8_t> buf(sizeof(double));   std::memcpy(buf.data(), &v, sizeof(double));   return buf;

    }
    size_t size_when_serialized_double(const double &v) {
        return sizeof(double);

    }
    double deserialize_double(const std::vector<uint8_t> &buf) {
        double v;   std::memcpy(&v, buf.data(), sizeof(double));   return v;

    }
    std::string short_to_string(const short &v) {
        return std::to_string(v);

    }
    short string_to_short(const std::string &s) {
        return static_cast<short>(std::stoi(s));

    }
    std::vector<uint8_t> serialize_short(const short &v) {
        std::vector<uint8_t> buf(sizeof(short));   std::memcpy(buf.data(), &v, sizeof(short));   return buf;

    }
    size_t size_when_serialized_short(const short &v) {
        return sizeof(short);

    }
    short deserialize_short(const std::vector<uint8_t> &buf) {
        short v;   std::memcpy(&v, buf.data(), sizeof(short));   return v;

    }
    std::string long_to_string(const long &v) {
        return std::to_string(v);

    }
    long string_to_long(const std::string &s) {
        return std::stol(s);

    }
    std::vector<uint8_t> serialize_long(const long &v) {
        std::vector<uint8_t> buf(sizeof(long));   std::memcpy(buf.data(), &v, sizeof(long));   return buf;

    }
    size_t size_when_serialized_long(const long &v) {
        return sizeof(long);

    }
    long deserialize_long(const std::vector<uint8_t> &buf) {
        long v;   std::memcpy(&v, buf.data(), sizeof(long));   return v;

    }
    std::string std_string_to_string(const std::string &s) {
        return s;

    }
    std::string string_to_std_string(const std::string &s) {
        if (s.size() >= 2 && s.front() == '"' && s.back() == '"')     return s.substr(1, s.size() - 2);   return s;

    }
    std::vector<uint8_t> serialize_std_string(const std::string &v) {
        std::vector<uint8_t> buf;   size_t len = v.size();   buf.resize(sizeof(size_t) + len);   std::memcpy(buf.data(), &len, sizeof(size_t));   std::memcpy(buf.data() + sizeof(size_t), v.data(), len);   return buf;

    }
    size_t size_when_serialized_std_string(const std::string &v) {
        return sizeof(size_t) + v.size();

    }
    std::string deserialize_std_string(const std::vector<uint8_t> &buf) {
        if (buf.size() < sizeof(size_t)) return std::string();   size_t len;   std::memcpy(&len, buf.data(), sizeof(size_t));   if (buf.size() < sizeof(size_t) + len) return std::string();   return std::string(reinterpret_cast<const char*>(buf.data() + sizeof(size_t)), len);

    }
    std::string std_filesystem_path_to_string(const std::filesystem::path &p) {
        return p.string();

    }
    std::filesystem::path string_to_std_filesystem_path(const std::string &s) {
        if (s.size() >= 2 && s.front() == '"' && s.back() == '"')     return std::filesystem::path(s.substr(1, s.size() - 2));   return std::filesystem::path(s);

    }
    std::vector<uint8_t> serialize_std_filesystem_path(const std::filesystem::path &p) {
        std::string s = p.string();   std::vector<uint8_t> buf;   size_t len = s.size();   buf.resize(sizeof(size_t) + len);   std::memcpy(buf.data(), &len, sizeof(size_t));   std::memcpy(buf.data() + sizeof(size_t), s.data(), len);   return buf;

    }
    size_t size_when_serialized_std_filesystem_path(const std::filesystem::path &p) {
        std::string s = p.string();   return sizeof(size_t) + s.size();

    }
    std::filesystem::path deserialize_std_filesystem_path(const std::vector<uint8_t> &buf) {
        if (buf.size() < sizeof(size_t)) return std::filesystem::path();   size_t len;   std::memcpy(&len, buf.data(), sizeof(size_t));   if (buf.size() < sizeof(size_t) + len) return std::filesystem::path();   return std::filesystem::path(std::string(reinterpret_cast<const char*>(buf.data() + sizeof(size_t)), len));

    }
    std::string bool_to_string(const bool &v) {
        return v ? "true" : "false";

    }
    bool string_to_bool(const std::string &s) {
        return s == "true";

    }
    std::vector<uint8_t> serialize_bool(const bool &v) {
        std::vector<uint8_t> buf(1);   buf[0] = v ? 1 : 0;   return buf;

    }
    size_t size_when_serialized_bool(const bool &v) {
        return sizeof(uint8_t);

    }
    bool deserialize_bool(const std::vector<uint8_t> &buf) {
        return buf[0] != 0;

    }
    std::string meta_utils_MetaType_to_string() {
        return "";

    }
    meta_utils::MetaType string_to_meta_utils_MetaType(const meta_utils::MetaType &mt) {

    }
    std::vector<uint8_t> serialize_meta_utils_MetaType() {

    }
    size_t size_when_serialized_meta_utils_MetaType(const meta_utils::MetaType &v) {
        return sizeof(meta_utils::MetaType);

    }
    meta_utils::MetaType deserialize_meta_utils_MetaType() {

    }
    std::string glm_vec2_to_string(const glm::vec2 &v) {
        int precision =  std::numeric_limits<float>::max_digits10; std::ostringstream oss; oss << std::fixed << std::setprecision(precision); oss << '(' << v.x << ',' << ' ' << v.y << ')'; return oss.str();

    }
    glm::vec2 string_to_glm_vec2(const std::string &s) {
        std::regex r(R"(\s*\(?\s*([-+]?[0-9]*\.?[0-9]+)\s*,\s*([-+]?[0-9]*\.?[0-9]+)\s*\)?\s*)");   std::smatch m;   if (std::regex_match(s, m, r)) {     return glm::vec2(std::stof(m[1]), std::stof(m[2]));   }   throw std::invalid_argument("Invalid glm::vec2 string");

    }
    std::vector<uint8_t> serialize_glm_vec2(const glm::vec2 &v) {
        std::vector<uint8_t> buf(sizeof(glm::vec2));   std::memcpy(buf.data(), &v, sizeof(glm::vec2));   return buf;

    }
    size_t size_when_serialized_glm_vec2(const glm::vec2 &v) {
        return sizeof(glm::vec2);

    }
    glm::vec2 deserialize_glm_vec2(const std::vector<uint8_t> &buf) {
        glm::vec2 v;   std::memcpy(&v, buf.data(), sizeof(glm::vec2));   return v;

    }
    std::string glm_vec3_to_string(const glm::vec3 &v) {
        int precision =  std::numeric_limits<float>::max_digits10; std::ostringstream oss; oss << std::fixed << std::setprecision(precision); oss << '(' << v.x << ',' << ' ' << v.y << ',' << ' ' << v.z <<  ')'; return oss.str();

    }
    glm::vec3 string_to_glm_vec3(const std::string &s) {
        std::regex r(R"(\s*\(?\s*([-+]?[0-9]*\.?[0-9]+)\s*,\s*([-+]?[0-9]*\.?[0-9]+)\s*,\s*([-+]?[0-9]*\.?[0-9]+)\s*\)?\s*)");   std::smatch m;   if (std::regex_match(s, m, r)) {     return glm::vec3(std::stof(m[1]), std::stof(m[2]), std::stof(m[3]));   }   throw std::invalid_argument("Invalid glm::vec3 string");

    }
    std::vector<uint8_t> serialize_glm_vec3(const glm::vec3 &v) {
        std::vector<uint8_t> buf(sizeof(glm::vec3));   std::memcpy(buf.data(), &v, sizeof(glm::vec3));   return buf;

    }
    size_t size_when_serialized_glm_vec3(const glm::vec3 &v) {
        return sizeof(glm::vec3);

    }
    glm::vec3 deserialize_glm_vec3(const std::vector<uint8_t> &buf) {
        glm::vec3 v;   std::memcpy(&v, buf.data(), sizeof(glm::vec3));   return v;

    }
    std::string glm_mat4_to_string(const glm::mat4 &m) {
        std::ostringstream oss;   oss << '[' << m[0][0] << ", " << m[0][1] << ", " << m[0][2] << ", " << m[0][3] << "]\n"       << '[' << m[1][0] << ", " << m[1][1] << ", " << m[1][2] << ", " << m[1][3] << "]\n"       << '[' << m[2][0] << ", " << m[2][1] << ", " << m[2][2] << ", " << m[2][3] << "]\n"       << '[' << m[3][0] << ", " << m[3][1] << ", " << m[3][2] << ", " << m[3][3] << ']';   return oss.str();

    }
    glm::mat4 string_to_glm_mat4(const std::string &s) {
        std::regex r(R"(([-+]?[0-9]*\.?[0-9]+))");   std::sregex_iterator it(s.begin(), s.end(), r), end;   std::vector<float> vals;   for (; it != end; ++it) vals.push_back(std::stof((*it)[1]));   if (vals.size() != 16)     throw std::invalid_argument("Invalid glm::mat4 string; expected 16 floats");   return glm::make_mat4(vals.data());

    }
    std::vector<uint8_t> serialize_glm_mat4(const glm::mat4 &m) {
        std::vector<uint8_t> buf(sizeof(glm::mat4));   std::memcpy(buf.data(), &m, sizeof(glm::mat4));   return buf;

    }
    size_t size_when_serialized_glm_mat4(const glm::mat4 &m) {
        return sizeof(glm::mat4);

    }
    glm::mat4 deserialize_glm_mat4(const std::vector<uint8_t> &buf) {
        glm::mat4 m;   std::memcpy(&m, buf.data(), sizeof(glm::mat4));   return m;

    }
    std::string JPH_Vec3_to_string(const JPH::Vec3 &v) {
        std::ostringstream oss;   oss << std::setprecision(std::numeric_limits<float>::max_digits10) << std::fixed;   oss << '(' << v.GetX() << ", " << v.GetY() << ", " << v.GetZ() << ')';   return oss.str();

    }
    JPH::Vec3 string_to_JPH_Vec3(const std::string &s) {
        std::regex r(R"(\s*\(?\s*([-+]?[0-9]*\.?[0-9]+)\s*,\s*([-+]?[0-9]*\.?[0-9]+)\s*,\s*([-+]?[0-9]*\.?[0-9]+)\s*\)?\s*)");   std::smatch m;   if (std::regex_match(s, m, r)) {     return JPH::Vec3(std::stof(m[1]), std::stof(m[2]), std::stof(m[3]));   }   throw std::invalid_argument("Invalid JPH::Vec3 string");

    }
    std::vector<uint8_t> serialize_JPH_Vec3(const JPH::Vec3 &v) {
        std::vector<uint8_t> buf(sizeof(JPH::Vec3));   std::memcpy(buf.data(), &v, sizeof(JPH::Vec3));   return buf;

    }
    size_t size_when_serialized_JPH_Vec3(const JPH::Vec3 &v) {
        return sizeof(JPH::Vec3);

    }
    JPH::Vec3 deserialize_JPH_Vec3(const std::vector<uint8_t> &buf) {
        JPH::Vec3 v;   std::memcpy(&v, buf.data(), sizeof(JPH::Vec3));   return v;

    }
    std::string JPH_Mat44_to_string(const JPH::Mat44 &m) {
        std::ostringstream oss;   for (int c = 0; c < 4; ++c) {     const JPH::Vec4 &col = m.GetColumn4(c);     oss << '[' << col.GetX() << ", " << col.GetY() << ", " << col.GetZ() << ", " << col.GetW() << ']';     if (c != 3) oss << '\n';   }   return oss.str();

    }
    JPH::Mat44 string_to_JPH_Mat44(const std::string &s) {
        std::regex r(R"(([-+]?[0-9]*\.?[0-9]+))");   std::sregex_iterator it(s.begin(), s.end(), r), end;   std::vector<float> vals;   for (; it != end; ++it) vals.push_back(std::stof((*it)[1]));   if (vals.size() != 16)     throw std::invalid_argument("Invalid JPH::Mat44 string; expected 16 floats");   JPH::Mat44 m;   m.SetColumn4(0, JPH::Vec4(vals[0], vals[1], vals[2], vals[3]));   m.SetColumn4(1, JPH::Vec4(vals[4], vals[5], vals[6], vals[7]));   m.SetColumn4(2, JPH::Vec4(vals[8], vals[9], vals[10], vals[11]));   m.SetColumn4(3, JPH::Vec4(vals[12], vals[13], vals[14], vals[15]));   return m;

    }
    std::vector<uint8_t> serialize_JPH_Mat44(const JPH::Mat44 &m) {
        std::vector<uint8_t> buf(sizeof(JPH::Mat44));   std::memcpy(buf.data(), &m, sizeof(JPH::Mat44));   return buf;

    }
    size_t size_when_serialized_JPH_Mat44(const JPH::Mat44 &m) {
        return sizeof(JPH::Mat44);

    }
    JPH::Mat44 deserialize_JPH_Mat44(const std::vector<uint8_t> &buf) {
        JPH::Mat44 m;   std::memcpy(&m, buf.data(), sizeof(JPH::Mat44));   return m;

    }
    std::string PacketType_to_string(PacketType value) {
        switch(value) {
                case PacketType::CLIENT_UPDATE_DATA: return "PacketType::CLIENT_UPDATE_DATA";
                case PacketType::GAME_STATE: return "PacketType::GAME_STATE";
                case PacketType::NUM_ENUMERATORS: return "PacketType::NUM_ENUMERATORS";
                default: return "<unknown PacketType>";
            }

    }
    PacketType string_to_PacketType(const std::string &s) {
        if (s == "PacketType::CLIENT_UPDATE_DATA") return PacketType::CLIENT_UPDATE_DATA;
            if (s == "PacketType::GAME_STATE") return PacketType::GAME_STATE;
            if (s == "PacketType::NUM_ENUMERATORS") return PacketType::NUM_ENUMERATORS;
            return static_cast<PacketType>(0); // default fallback

    }
    std::vector<uint8_t> serialize_PacketType(PacketType value) {
        std::vector<uint8_t> buffer(sizeof(uint8_t));
            uint8_t raw = static_cast<uint8_t>(value);
            std::memcpy(buffer.data(), &raw, sizeof(uint8_t));
            return buffer;

    }
    size_t size_when_serialized_PacketType(const PacketType &obj) {
        return sizeof(uint8_t);

    }
    PacketType deserialize_PacketType(const std::vector<uint8_t> &buffer) {
        if (buffer.size() < sizeof(uint8_t)) return static_cast<PacketType>(0);
            uint8_t raw = 0;
            std::memcpy(&raw, buffer.data(), sizeof(uint8_t));
            return static_cast<PacketType>(raw);

    }
    std::string PacketHeader_to_string(const PacketHeader obj) {
        std::ostringstream oss;
            oss << "{";
            { auto conv = [=](PacketType value) -> std::string {
            switch(value) {
                case PacketType::CLIENT_UPDATE_DATA: return "PacketType::CLIENT_UPDATE_DATA";
                case PacketType::GAME_STATE: return "PacketType::GAME_STATE";
                case PacketType::NUM_ENUMERATORS: return "PacketType::NUM_ENUMERATORS";
                default: return "<unknown PacketType>";
            }
        };
              oss << "type=" << conv(obj.type); }
            oss << ", ";
            { auto conv = [](const uint32_t &v) { return std::to_string(v); };
              oss << "size_of_data_without_header=" << conv(obj.size_of_data_without_header); }
            oss << "}";
            return oss.str();

    }
    PacketHeader string_to_PacketHeader(const std::string &s) {
        PacketHeader obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &s) -> PacketType {
            if (s == "PacketType::CLIENT_UPDATE_DATA") return PacketType::CLIENT_UPDATE_DATA;
            if (s == "PacketType::GAME_STATE") return PacketType::GAME_STATE;
            if (s == "PacketType::NUM_ENUMERATORS") return PacketType::NUM_ENUMERATORS;
            return static_cast<PacketType>(0); // default fallback
        };
                    obj.type = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return static_cast<uint32_t>(std::stoul(s)); };
                    obj.size_of_data_without_header = conv(value_str);
                }
            }
            return obj;

    }
    std::vector<uint8_t> serialize_PacketHeader(const PacketHeader obj) {
        std::vector<uint8_t> buffer;
            { auto ser = [=](PacketType value) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer(sizeof(uint8_t));
            uint8_t raw = static_cast<uint8_t>(value);
            std::memcpy(buffer.data(), &raw, sizeof(uint8_t));
            return buffer;
        };
              auto bytes = ser(obj.type);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const uint32_t &v) {   std::vector<uint8_t> buf(sizeof(uint32_t));   std::memcpy(buf.data(), &v, sizeof(uint32_t));   return buf; };
              auto bytes = ser(obj.size_of_data_without_header);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;

    }
    size_t size_when_serialized_PacketHeader(const PacketHeader obj) {
        size_t total = 0;
            { auto size_fn = [=](const PacketType &obj) -> size_t {
            return sizeof(uint8_t);
        };
              total += size_fn(obj.type); }
            { auto size_fn = [](const uint32_t &v) { return sizeof(uint32_t); };
              total += size_fn(obj.size_of_data_without_header); }
            return total;

    }
    PacketHeader deserialize_PacketHeader(const std::vector<uint8_t> &buffer) {
        PacketHeader obj;
            size_t offset = 0;
            { auto deser = [=](const std::vector<uint8_t> &buffer) -> PacketType {
            if (buffer.size() < sizeof(uint8_t)) return static_cast<PacketType>(0);
            uint8_t raw = 0;
            std::memcpy(&raw, buffer.data(), sizeof(uint8_t));
            return static_cast<PacketType>(raw);
        };
              auto size_fn = [=](const PacketType &obj) -> size_t {
            return sizeof(uint8_t);
        };
              size_t len = size_fn(obj.type);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.type = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   uint32_t v;   std::memcpy(&v, buf.data(), sizeof(uint32_t));   return v; };
              auto size_fn = [](const uint32_t &v) { return sizeof(uint32_t); };
              size_t len = size_fn(obj.size_of_data_without_header);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.size_of_data_without_header = deser(slice);
              offset += len;
            }
            return obj;

    }
    std::string PacketWithSize_to_string(const PacketWithSize obj) {
        std::ostringstream oss;
            oss << "{";
            { auto conv = [=](const std::vector<char>& vec) -> std::string {
            std::ostringstream oss;
            oss << "{";
            auto conversion = [](const char &v) { return std::to_string(v); };
        
            for (size_t i = 0; i < vec.size(); ++i) {
                oss << conversion(vec[i]);
                if (i + 1 < vec.size())
                    oss << ", ";
            }
        
            oss << "}";
            return oss.str();
        };
              oss << "data=" << conv(obj.data); }
            oss << ", ";
            { auto conv = [](const size_t &v) { return std::to_string(v); };
              oss << "size=" << conv(obj.size); }
            oss << "}";
            return oss.str();

    }
    PacketWithSize string_to_PacketWithSize(const std::string &s) {
        PacketWithSize obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &input) -> std::vector<char> {
            std::string trimmed = input;
            if (!trimmed.empty() && trimmed.front() == '{' && trimmed.back() == '}') {
                trimmed = trimmed.substr(1, trimmed.size() - 2);
            }
        
            std::vector<char> result;
            std::regex element_re(R"('(?:[^'\\]|\\.)')");
            auto begin = std::sregex_iterator(trimmed.begin(), trimmed.end(), element_re);
            auto end = std::sregex_iterator();
        
            for (auto it = begin; it != end; ++it) {
                try {
                    auto conversion = [](const std::string &s) { return static_cast<char>(s.empty() ? 0 : s[0]); };
                    result.push_back(conversion(it->str()));
                } catch (...) {
                    // Ignore malformed elements
                }
            }
            return result;
        };
                    obj.data = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return static_cast<size_t>(std::stoull(s)); };
                    obj.size = conv(value_str);
                }
            }
            return obj;

    }
    std::vector<uint8_t> serialize_PacketWithSize(const PacketWithSize obj) {
        std::vector<uint8_t> buffer;
            { auto ser = [=](const std::vector<char>& vec) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            // store vector size first, which is necessary or else we won't know when to stop during deserialization
            size_t count = vec.size();
            buffer.resize(sizeof(size_t));
            std::memcpy(buffer.data(), &count, sizeof(size_t));
        
            auto element_serializer = [](const char &v) {   std::vector<uint8_t> buf(sizeof(char));   std::memcpy(buf.data(), &v, sizeof(char));   return buf; };
            for (const auto& elem : vec) {
                auto elem_bytes = element_serializer(elem);
                buffer.insert(buffer.end(), elem_bytes.begin(), elem_bytes.end());
            }
            return buffer;
        };
              auto bytes = ser(obj.data);
              size_t len = bytes.size();
              buffer.resize(buffer.size() + sizeof(size_t));
              std::memcpy(buffer.data() + buffer.size() - sizeof(size_t), &len, sizeof(size_t));
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const size_t &v) {   std::vector<uint8_t> buf(sizeof(size_t));   std::memcpy(buf.data(), &v, sizeof(size_t));   return buf; };
              auto bytes = ser(obj.size);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;

    }
    size_t size_when_serialized_PacketWithSize(const PacketWithSize obj) {
        size_t total = 0;
            { auto size_fn = [=](const std::vector<char>& vec) -> size_t {
            size_t total_size = sizeof(size_t); // space for storing count
            if (!vec.empty()) {
                total_size += vec.size() * [](const char &v) { return sizeof(char); }(vec[0]);
            }
            return total_size;
        };
              total += sizeof(size_t); // length prefix
              total += size_fn(obj.data); }
            { auto size_fn = [](const size_t &v) { return sizeof(size_t); };
              total += size_fn(obj.size); }
            return total;

    }
    PacketWithSize deserialize_PacketWithSize(const std::vector<uint8_t> &buffer) {
        PacketWithSize obj;
            size_t offset = 0;
            { auto deser = [=](const std::vector<uint8_t>& buffer) -> std::vector<char> {
            std::vector<char> result;
            if (buffer.size() < sizeof(size_t)) return result;
            size_t count;
            std::memcpy(&count, buffer.data(), sizeof(size_t));
        
            size_t offset = sizeof(size_t);
            auto element_deserializer = [](const std::vector<uint8_t> &buf) {   char v;   std::memcpy(&v, buf.data(), sizeof(char));   return v; };
            // NOTE: big assumption, assumes the default constructor exists for this object. There's gotta be a better way, what if we made size when serialized take in an optional value.
            char dummy; 
            auto size_fn = [](const char &v) { return sizeof(char); };
            size_t elem_size = size_fn(dummy);
            if (offset + count * elem_size > buffer.size()) return result; // safety check
            for (size_t i = 0; i < count; ++i) {
                std::vector<uint8_t> elem_buf(buffer.begin() + offset, buffer.begin() + offset + elem_size);
                char elem = element_deserializer(elem_buf);
                result.push_back(elem);
                offset += elem_size;
            }
            return result;
        };
              if (offset + sizeof(size_t) > buffer.size()) return obj;
              size_t len = 0;
              std::memcpy(&len, buffer.data() + offset, sizeof(size_t));
              offset += sizeof(size_t);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.data = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   size_t v;   std::memcpy(&v, buf.data(), sizeof(size_t));   return v; };
              auto size_fn = [](const size_t &v) { return sizeof(size_t); };
              size_t len = size_fn(obj.size);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.size = deser(slice);
              offset += len;
            }
            return obj;

    }
    std::string SoundType_to_string(SoundType value) {
        switch(value) {
                case SoundType::UI_HOVER: return "SoundType::UI_HOVER";
                case SoundType::UI_CLICK: return "SoundType::UI_CLICK";
                case SoundType::UI_SUCCESS: return "SoundType::UI_SUCCESS";
                case SoundType::CLIENT_HIT: return "SoundType::CLIENT_HIT";
                case SoundType::CLIENT_MISS: return "SoundType::CLIENT_MISS";
                case SoundType::SERVER_HIT: return "SoundType::SERVER_HIT";
                case SoundType::SERVER_MISS: return "SoundType::SERVER_MISS";
                default: return "<unknown SoundType>";
            }

    }
    SoundType string_to_SoundType(const std::string &s) {
        if (s == "SoundType::UI_HOVER") return SoundType::UI_HOVER;
            if (s == "SoundType::UI_CLICK") return SoundType::UI_CLICK;
            if (s == "SoundType::UI_SUCCESS") return SoundType::UI_SUCCESS;
            if (s == "SoundType::CLIENT_HIT") return SoundType::CLIENT_HIT;
            if (s == "SoundType::CLIENT_MISS") return SoundType::CLIENT_MISS;
            if (s == "SoundType::SERVER_HIT") return SoundType::SERVER_HIT;
            if (s == "SoundType::SERVER_MISS") return SoundType::SERVER_MISS;
            return static_cast<SoundType>(0); // default fallback

    }
    std::vector<uint8_t> serialize_SoundType(SoundType value) {
        std::vector<uint8_t> buffer(sizeof(int));
            int raw = static_cast<int>(value);
            std::memcpy(buffer.data(), &raw, sizeof(int));
            return buffer;

    }
    size_t size_when_serialized_SoundType(const SoundType &obj) {
        return sizeof(int);

    }
    SoundType deserialize_SoundType(const std::vector<uint8_t> &buffer) {
        if (buffer.size() < sizeof(int)) return static_cast<SoundType>(0);
            int raw = 0;
            std::memcpy(&raw, buffer.data(), sizeof(int));
            return static_cast<SoundType>(raw);

    }
    std::string DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer_to_string(const DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer obj) {
        std::ostringstream oss;
            oss << "{";
            { auto conv = [](const unsigned int &v) { return std::to_string(v); };
              oss << "id_of_interpolation_start_game_state_id_for_non_local_character_state=" << conv(obj.id_of_interpolation_start_game_state_id_for_non_local_character_state); }
            oss << ", ";
            { auto conv = [](const unsigned int &v) { return std::to_string(v); };
              oss << "id_of_interpolation_end_game_state_id_for_non_local_character_state=" << conv(obj.id_of_interpolation_end_game_state_id_for_non_local_character_state); }
            oss << ", ";
            { auto conv = [](const double &v) {  std::ostringstream oss;  oss << std::setprecision(std::numeric_limits<double>::max_digits10) << v;  return oss.str();};
              oss << "interpolation_percent_when_fired=" << conv(obj.interpolation_percent_when_fired); }
            oss << "}";
            return oss.str();

    }
    DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer string_to_DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer(const std::string &s) {
        DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return static_cast<unsigned int>(std::stoul(s)); };
                    obj.id_of_interpolation_start_game_state_id_for_non_local_character_state = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return static_cast<unsigned int>(std::stoul(s)); };
                    obj.id_of_interpolation_end_game_state_id_for_non_local_character_state = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return std::stod(s); };
                    obj.interpolation_percent_when_fired = conv(value_str);
                }
            }
            return obj;

    }
    std::vector<uint8_t> serialize_DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer(const DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer obj) {
        std::vector<uint8_t> buffer;
            { auto ser = [](const unsigned int &v) {   std::vector<uint8_t> buf(sizeof(unsigned int));   std::memcpy(buf.data(), &v, sizeof(unsigned int));   return buf; };
              auto bytes = ser(obj.id_of_interpolation_start_game_state_id_for_non_local_character_state);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const unsigned int &v) {   std::vector<uint8_t> buf(sizeof(unsigned int));   std::memcpy(buf.data(), &v, sizeof(unsigned int));   return buf; };
              auto bytes = ser(obj.id_of_interpolation_end_game_state_id_for_non_local_character_state);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const double &v) {   std::vector<uint8_t> buf(sizeof(double));   std::memcpy(buf.data(), &v, sizeof(double));   return buf; };
              auto bytes = ser(obj.interpolation_percent_when_fired);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;

    }
    size_t size_when_serialized_DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer(const DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer obj) {
        size_t total = 0;
            { auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              total += size_fn(obj.id_of_interpolation_start_game_state_id_for_non_local_character_state); }
            { auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              total += size_fn(obj.id_of_interpolation_end_game_state_id_for_non_local_character_state); }
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.interpolation_percent_when_fired); }
            return total;

    }
    DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer deserialize_DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer(const std::vector<uint8_t> &buffer) {
        DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   unsigned int v;   std::memcpy(&v, buf.data(), sizeof(unsigned int));   return v; };
              auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              size_t len = size_fn(obj.id_of_interpolation_start_game_state_id_for_non_local_character_state);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.id_of_interpolation_start_game_state_id_for_non_local_character_state = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   unsigned int v;   std::memcpy(&v, buf.data(), sizeof(unsigned int));   return v; };
              auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              size_t len = size_fn(obj.id_of_interpolation_end_game_state_id_for_non_local_character_state);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.id_of_interpolation_end_game_state_id_for_non_local_character_state = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   double v;   std::memcpy(&v, buf.data(), sizeof(double));   return v; };
              auto size_fn = [](const double &v) { return sizeof(double); };
              size_t len = size_fn(obj.interpolation_percent_when_fired);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.interpolation_percent_when_fired = deser(slice);
              offset += len;
            }
            return obj;

    }
    std::string DataToReconstructClientGameStateWhenFiringOnServer_to_string(const DataToReconstructClientGameStateWhenFiringOnServer obj) {
        std::ostringstream oss;
            oss << "{";
            { auto conv = [=](const DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer& obj) -> std::string {
            std::ostringstream oss;
            oss << "{";
            { auto conv = [](const unsigned int &v) { return std::to_string(v); };
              oss << "id_of_interpolation_start_game_state_id_for_non_local_character_state=" << conv(obj.id_of_interpolation_start_game_state_id_for_non_local_character_state); }
            oss << ", ";
            { auto conv = [](const unsigned int &v) { return std::to_string(v); };
              oss << "id_of_interpolation_end_game_state_id_for_non_local_character_state=" << conv(obj.id_of_interpolation_end_game_state_id_for_non_local_character_state); }
            oss << ", ";
            { auto conv = [](const double &v) {  std::ostringstream oss;  oss << std::setprecision(std::numeric_limits<double>::max_digits10) << v;  return oss.str();};
              oss << "interpolation_percent_when_fired=" << conv(obj.interpolation_percent_when_fired); }
            oss << "}";
            return oss.str();
        };
              oss << "data_to_reconstruct_non_local_character_physics_state_with_entity_interpolation_when_firing_on_server=" << conv(obj.data_to_reconstruct_non_local_character_physics_state_with_entity_interpolation_when_firing_on_server); }
            oss << "}";
            return oss.str();

    }
    DataToReconstructClientGameStateWhenFiringOnServer string_to_DataToReconstructClientGameStateWhenFiringOnServer(const std::string &s) {
        DataToReconstructClientGameStateWhenFiringOnServer obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &s) -> DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer {
            DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return static_cast<unsigned int>(std::stoul(s)); };
                    obj.id_of_interpolation_start_game_state_id_for_non_local_character_state = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return static_cast<unsigned int>(std::stoul(s)); };
                    obj.id_of_interpolation_end_game_state_id_for_non_local_character_state = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return std::stod(s); };
                    obj.interpolation_percent_when_fired = conv(value_str);
                }
            }
            return obj;
        };
                    obj.data_to_reconstruct_non_local_character_physics_state_with_entity_interpolation_when_firing_on_server = conv(value_str);
                }
            }
            return obj;

    }
    std::vector<uint8_t> serialize_DataToReconstructClientGameStateWhenFiringOnServer(const DataToReconstructClientGameStateWhenFiringOnServer obj) {
        std::vector<uint8_t> buffer;
            { auto ser = [=](const DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer& obj) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            { auto ser = [](const unsigned int &v) {   std::vector<uint8_t> buf(sizeof(unsigned int));   std::memcpy(buf.data(), &v, sizeof(unsigned int));   return buf; };
              auto bytes = ser(obj.id_of_interpolation_start_game_state_id_for_non_local_character_state);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const unsigned int &v) {   std::vector<uint8_t> buf(sizeof(unsigned int));   std::memcpy(buf.data(), &v, sizeof(unsigned int));   return buf; };
              auto bytes = ser(obj.id_of_interpolation_end_game_state_id_for_non_local_character_state);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const double &v) {   std::vector<uint8_t> buf(sizeof(double));   std::memcpy(buf.data(), &v, sizeof(double));   return buf; };
              auto bytes = ser(obj.interpolation_percent_when_fired);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;
        };
              auto bytes = ser(obj.data_to_reconstruct_non_local_character_physics_state_with_entity_interpolation_when_firing_on_server);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;

    }
    size_t size_when_serialized_DataToReconstructClientGameStateWhenFiringOnServer(const DataToReconstructClientGameStateWhenFiringOnServer obj) {
        size_t total = 0;
            { auto size_fn = [=](const DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              total += size_fn(obj.id_of_interpolation_start_game_state_id_for_non_local_character_state); }
            { auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              total += size_fn(obj.id_of_interpolation_end_game_state_id_for_non_local_character_state); }
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.interpolation_percent_when_fired); }
            return total;
        };
              total += size_fn(obj.data_to_reconstruct_non_local_character_physics_state_with_entity_interpolation_when_firing_on_server); }
            return total;

    }
    DataToReconstructClientGameStateWhenFiringOnServer deserialize_DataToReconstructClientGameStateWhenFiringOnServer(const std::vector<uint8_t> &buffer) {
        DataToReconstructClientGameStateWhenFiringOnServer obj;
            size_t offset = 0;
            { auto deser = [=](const std::vector<uint8_t> &buffer) -> DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer {
            DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   unsigned int v;   std::memcpy(&v, buf.data(), sizeof(unsigned int));   return v; };
              auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              size_t len = size_fn(obj.id_of_interpolation_start_game_state_id_for_non_local_character_state);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.id_of_interpolation_start_game_state_id_for_non_local_character_state = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   unsigned int v;   std::memcpy(&v, buf.data(), sizeof(unsigned int));   return v; };
              auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              size_t len = size_fn(obj.id_of_interpolation_end_game_state_id_for_non_local_character_state);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.id_of_interpolation_end_game_state_id_for_non_local_character_state = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   double v;   std::memcpy(&v, buf.data(), sizeof(double));   return v; };
              auto size_fn = [](const double &v) { return sizeof(double); };
              size_t len = size_fn(obj.interpolation_percent_when_fired);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.interpolation_percent_when_fired = deser(slice);
              offset += len;
            }
            return obj;
        };
              auto size_fn = [=](const DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              total += size_fn(obj.id_of_interpolation_start_game_state_id_for_non_local_character_state); }
            { auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              total += size_fn(obj.id_of_interpolation_end_game_state_id_for_non_local_character_state); }
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.interpolation_percent_when_fired); }
            return total;
        };
              size_t len = size_fn(obj.data_to_reconstruct_non_local_character_physics_state_with_entity_interpolation_when_firing_on_server);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.data_to_reconstruct_non_local_character_physics_state_with_entity_interpolation_when_firing_on_server = deser(slice);
              offset += len;
            }
            return obj;

    }
    std::string ClientInputState_to_string(const ClientInputState obj) {
        std::ostringstream oss;
            oss << "{";
            { auto conv = [](const bool &v) { return v ? "true" : "false"; };
              oss << "forward_pressed=" << conv(obj.forward_pressed); }
            oss << ", ";
            { auto conv = [](const bool &v) { return v ? "true" : "false"; };
              oss << "back_pressed=" << conv(obj.back_pressed); }
            oss << ", ";
            { auto conv = [](const bool &v) { return v ? "true" : "false"; };
              oss << "right_pressed=" << conv(obj.right_pressed); }
            oss << ", ";
            { auto conv = [](const bool &v) { return v ? "true" : "false"; };
              oss << "left_pressed=" << conv(obj.left_pressed); }
            oss << ", ";
            { auto conv = [](const bool &v) { return v ? "true" : "false"; };
              oss << "jump_pressed=" << conv(obj.jump_pressed); }
            oss << "}";
            return oss.str();

    }
    ClientInputState string_to_ClientInputState(const std::string &s) {
        ClientInputState obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return s == "true"; };
                    obj.forward_pressed = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return s == "true"; };
                    obj.back_pressed = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return s == "true"; };
                    obj.right_pressed = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return s == "true"; };
                    obj.left_pressed = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return s == "true"; };
                    obj.jump_pressed = conv(value_str);
                }
            }
            return obj;

    }
    std::vector<uint8_t> serialize_ClientInputState(const ClientInputState obj) {
        std::vector<uint8_t> buffer;
            { auto ser = [](const bool &v) {   std::vector<uint8_t> buf(1);   buf[0] = v ? 1 : 0;   return buf; };
              auto bytes = ser(obj.forward_pressed);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const bool &v) {   std::vector<uint8_t> buf(1);   buf[0] = v ? 1 : 0;   return buf; };
              auto bytes = ser(obj.back_pressed);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const bool &v) {   std::vector<uint8_t> buf(1);   buf[0] = v ? 1 : 0;   return buf; };
              auto bytes = ser(obj.right_pressed);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const bool &v) {   std::vector<uint8_t> buf(1);   buf[0] = v ? 1 : 0;   return buf; };
              auto bytes = ser(obj.left_pressed);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const bool &v) {   std::vector<uint8_t> buf(1);   buf[0] = v ? 1 : 0;   return buf; };
              auto bytes = ser(obj.jump_pressed);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;

    }
    size_t size_when_serialized_ClientInputState(const ClientInputState obj) {
        size_t total = 0;
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.forward_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.back_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.right_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.left_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.jump_pressed); }
            return total;

    }
    ClientInputState deserialize_ClientInputState(const std::vector<uint8_t> &buffer) {
        ClientInputState obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   return buf[0] != 0; };
              auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              size_t len = size_fn(obj.forward_pressed);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.forward_pressed = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   return buf[0] != 0; };
              auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              size_t len = size_fn(obj.back_pressed);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.back_pressed = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   return buf[0] != 0; };
              auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              size_t len = size_fn(obj.right_pressed);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.right_pressed = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   return buf[0] != 0; };
              auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              size_t len = size_fn(obj.left_pressed);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.left_pressed = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   return buf[0] != 0; };
              auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              size_t len = size_fn(obj.jump_pressed);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.jump_pressed = deser(slice);
              offset += len;
            }
            return obj;

    }
    std::string CharacterPhysicsState_to_string(const CharacterPhysicsState obj) {
        std::ostringstream oss;
            oss << "{";
            { auto conv = [](const JPH::Vec3 &v) {   std::ostringstream oss;   oss << std::setprecision(std::numeric_limits<float>::max_digits10) << std::fixed;   oss << '(' << v.GetX() << ", " << v.GetY() << ", " << v.GetZ() << ')';   return oss.str(); };
              oss << "position=" << conv(obj.position); }
            oss << ", ";
            { auto conv = [](const JPH::Vec3 &v) {   std::ostringstream oss;   oss << std::setprecision(std::numeric_limits<float>::max_digits10) << std::fixed;   oss << '(' << v.GetX() << ", " << v.GetY() << ", " << v.GetZ() << ')';   return oss.str(); };
              oss << "velocity=" << conv(obj.velocity); }
            oss << "}";
            return oss.str();

    }
    CharacterPhysicsState string_to_CharacterPhysicsState(const std::string &s) {
        CharacterPhysicsState obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) {   std::regex r(R"(\s*\(?\s*([-+]?[0-9]*\.?[0-9]+)\s*,\s*([-+]?[0-9]*\.?[0-9]+)\s*,\s*([-+]?[0-9]*\.?[0-9]+)\s*\)?\s*)");   std::smatch m;   if (std::regex_match(s, m, r)) {     return JPH::Vec3(std::stof(m[1]), std::stof(m[2]), std::stof(m[3]));   }   throw std::invalid_argument("Invalid JPH::Vec3 string"); };
                    obj.position = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) {   std::regex r(R"(\s*\(?\s*([-+]?[0-9]*\.?[0-9]+)\s*,\s*([-+]?[0-9]*\.?[0-9]+)\s*,\s*([-+]?[0-9]*\.?[0-9]+)\s*\)?\s*)");   std::smatch m;   if (std::regex_match(s, m, r)) {     return JPH::Vec3(std::stof(m[1]), std::stof(m[2]), std::stof(m[3]));   }   throw std::invalid_argument("Invalid JPH::Vec3 string"); };
                    obj.velocity = conv(value_str);
                }
            }
            return obj;

    }
    std::vector<uint8_t> serialize_CharacterPhysicsState(const CharacterPhysicsState obj) {
        std::vector<uint8_t> buffer;
            { auto ser = [](const JPH::Vec3 &v) {   std::vector<uint8_t> buf(sizeof(JPH::Vec3));   std::memcpy(buf.data(), &v, sizeof(JPH::Vec3));   return buf; };
              auto bytes = ser(obj.position);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const JPH::Vec3 &v) {   std::vector<uint8_t> buf(sizeof(JPH::Vec3));   std::memcpy(buf.data(), &v, sizeof(JPH::Vec3));   return buf; };
              auto bytes = ser(obj.velocity);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;

    }
    size_t size_when_serialized_CharacterPhysicsState(const CharacterPhysicsState obj) {
        size_t total = 0;
            { auto size_fn = [](const JPH::Vec3 &v) { return sizeof(JPH::Vec3); };
              total += size_fn(obj.position); }
            { auto size_fn = [](const JPH::Vec3 &v) { return sizeof(JPH::Vec3); };
              total += size_fn(obj.velocity); }
            return total;

    }
    CharacterPhysicsState deserialize_CharacterPhysicsState(const std::vector<uint8_t> &buffer) {
        CharacterPhysicsState obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   JPH::Vec3 v;   std::memcpy(&v, buf.data(), sizeof(JPH::Vec3));   return v; };
              auto size_fn = [](const JPH::Vec3 &v) { return sizeof(JPH::Vec3); };
              size_t len = size_fn(obj.position);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.position = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   JPH::Vec3 v;   std::memcpy(&v, buf.data(), sizeof(JPH::Vec3));   return v; };
              auto size_fn = [](const JPH::Vec3 &v) { return sizeof(JPH::Vec3); };
              size_t len = size_fn(obj.velocity);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.velocity = deser(slice);
              offset += len;
            }
            return obj;

    }
    std::string IdTaggedCharacterPhysicsState_to_string(const IdTaggedCharacterPhysicsState obj) {
        std::ostringstream oss;
            oss << "{";
            { auto conv = [](const unsigned int &v) { return std::to_string(v); };
              oss << "id_of_last_update_data_used_to_produce_this_state=" << conv(obj.id_of_last_update_data_used_to_produce_this_state); }
            oss << ", ";
            { auto conv = [=](const CharacterPhysicsState& obj) -> std::string {
            std::ostringstream oss;
            oss << "{";
            { auto conv = [](const JPH::Vec3 &v) {   std::ostringstream oss;   oss << std::setprecision(std::numeric_limits<float>::max_digits10) << std::fixed;   oss << '(' << v.GetX() << ", " << v.GetY() << ", " << v.GetZ() << ')';   return oss.str(); };
              oss << "position=" << conv(obj.position); }
            oss << ", ";
            { auto conv = [](const JPH::Vec3 &v) {   std::ostringstream oss;   oss << std::setprecision(std::numeric_limits<float>::max_digits10) << std::fixed;   oss << '(' << v.GetX() << ", " << v.GetY() << ", " << v.GetZ() << ')';   return oss.str(); };
              oss << "velocity=" << conv(obj.velocity); }
            oss << "}";
            return oss.str();
        };
              oss << "character_physics_state=" << conv(obj.character_physics_state); }
            oss << "}";
            return oss.str();

    }
    IdTaggedCharacterPhysicsState string_to_IdTaggedCharacterPhysicsState(const std::string &s) {
        IdTaggedCharacterPhysicsState obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return static_cast<unsigned int>(std::stoul(s)); };
                    obj.id_of_last_update_data_used_to_produce_this_state = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &s) -> CharacterPhysicsState {
            CharacterPhysicsState obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) {   std::regex r(R"(\s*\(?\s*([-+]?[0-9]*\.?[0-9]+)\s*,\s*([-+]?[0-9]*\.?[0-9]+)\s*,\s*([-+]?[0-9]*\.?[0-9]+)\s*\)?\s*)");   std::smatch m;   if (std::regex_match(s, m, r)) {     return JPH::Vec3(std::stof(m[1]), std::stof(m[2]), std::stof(m[3]));   }   throw std::invalid_argument("Invalid JPH::Vec3 string"); };
                    obj.position = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) {   std::regex r(R"(\s*\(?\s*([-+]?[0-9]*\.?[0-9]+)\s*,\s*([-+]?[0-9]*\.?[0-9]+)\s*,\s*([-+]?[0-9]*\.?[0-9]+)\s*\)?\s*)");   std::smatch m;   if (std::regex_match(s, m, r)) {     return JPH::Vec3(std::stof(m[1]), std::stof(m[2]), std::stof(m[3]));   }   throw std::invalid_argument("Invalid JPH::Vec3 string"); };
                    obj.velocity = conv(value_str);
                }
            }
            return obj;
        };
                    obj.character_physics_state = conv(value_str);
                }
            }
            return obj;

    }
    std::vector<uint8_t> serialize_IdTaggedCharacterPhysicsState(const IdTaggedCharacterPhysicsState obj) {
        std::vector<uint8_t> buffer;
            { auto ser = [](const unsigned int &v) {   std::vector<uint8_t> buf(sizeof(unsigned int));   std::memcpy(buf.data(), &v, sizeof(unsigned int));   return buf; };
              auto bytes = ser(obj.id_of_last_update_data_used_to_produce_this_state);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [=](const CharacterPhysicsState& obj) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            { auto ser = [](const JPH::Vec3 &v) {   std::vector<uint8_t> buf(sizeof(JPH::Vec3));   std::memcpy(buf.data(), &v, sizeof(JPH::Vec3));   return buf; };
              auto bytes = ser(obj.position);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const JPH::Vec3 &v) {   std::vector<uint8_t> buf(sizeof(JPH::Vec3));   std::memcpy(buf.data(), &v, sizeof(JPH::Vec3));   return buf; };
              auto bytes = ser(obj.velocity);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;
        };
              auto bytes = ser(obj.character_physics_state);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;

    }
    size_t size_when_serialized_IdTaggedCharacterPhysicsState(const IdTaggedCharacterPhysicsState obj) {
        size_t total = 0;
            { auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              total += size_fn(obj.id_of_last_update_data_used_to_produce_this_state); }
            { auto size_fn = [=](const CharacterPhysicsState& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const JPH::Vec3 &v) { return sizeof(JPH::Vec3); };
              total += size_fn(obj.position); }
            { auto size_fn = [](const JPH::Vec3 &v) { return sizeof(JPH::Vec3); };
              total += size_fn(obj.velocity); }
            return total;
        };
              total += size_fn(obj.character_physics_state); }
            return total;

    }
    IdTaggedCharacterPhysicsState deserialize_IdTaggedCharacterPhysicsState(const std::vector<uint8_t> &buffer) {
        IdTaggedCharacterPhysicsState obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   unsigned int v;   std::memcpy(&v, buf.data(), sizeof(unsigned int));   return v; };
              auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              size_t len = size_fn(obj.id_of_last_update_data_used_to_produce_this_state);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.id_of_last_update_data_used_to_produce_this_state = deser(slice);
              offset += len;
            }
            { auto deser = [=](const std::vector<uint8_t> &buffer) -> CharacterPhysicsState {
            CharacterPhysicsState obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   JPH::Vec3 v;   std::memcpy(&v, buf.data(), sizeof(JPH::Vec3));   return v; };
              auto size_fn = [](const JPH::Vec3 &v) { return sizeof(JPH::Vec3); };
              size_t len = size_fn(obj.position);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.position = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   JPH::Vec3 v;   std::memcpy(&v, buf.data(), sizeof(JPH::Vec3));   return v; };
              auto size_fn = [](const JPH::Vec3 &v) { return sizeof(JPH::Vec3); };
              size_t len = size_fn(obj.velocity);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.velocity = deser(slice);
              offset += len;
            }
            return obj;
        };
              auto size_fn = [=](const CharacterPhysicsState& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const JPH::Vec3 &v) { return sizeof(JPH::Vec3); };
              total += size_fn(obj.position); }
            { auto size_fn = [](const JPH::Vec3 &v) { return sizeof(JPH::Vec3); };
              total += size_fn(obj.velocity); }
            return total;
        };
              size_t len = size_fn(obj.character_physics_state);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.character_physics_state = deser(slice);
              offset += len;
            }
            return obj;

    }
    std::string CharacterPhysicsUpdateData_to_string(const CharacterPhysicsUpdateData obj) {
        std::ostringstream oss;
            oss << "{";
            { auto conv = [](const double &v) {  std::ostringstream oss;  oss << std::setprecision(std::numeric_limits<double>::max_digits10) << v;  return oss.str();};
              oss << "dt=" << conv(obj.dt); }
            oss << ", ";
            { auto conv = [=](const ClientInputState& obj) -> std::string {
            std::ostringstream oss;
            oss << "{";
            { auto conv = [](const bool &v) { return v ? "true" : "false"; };
              oss << "forward_pressed=" << conv(obj.forward_pressed); }
            oss << ", ";
            { auto conv = [](const bool &v) { return v ? "true" : "false"; };
              oss << "back_pressed=" << conv(obj.back_pressed); }
            oss << ", ";
            { auto conv = [](const bool &v) { return v ? "true" : "false"; };
              oss << "right_pressed=" << conv(obj.right_pressed); }
            oss << ", ";
            { auto conv = [](const bool &v) { return v ? "true" : "false"; };
              oss << "left_pressed=" << conv(obj.left_pressed); }
            oss << ", ";
            { auto conv = [](const bool &v) { return v ? "true" : "false"; };
              oss << "jump_pressed=" << conv(obj.jump_pressed); }
            oss << "}";
            return oss.str();
        };
              oss << "client_input_state=" << conv(obj.client_input_state); }
            oss << ", ";
            { auto conv = [](const glm::vec3 &v) {  int precision =  std::numeric_limits<float>::max_digits10; std::ostringstream oss; oss << std::fixed << std::setprecision(precision); oss << '(' << v.x << ',' << ' ' << v.y << ',' << ' ' << v.z <<  ')'; return oss.str();};
              oss << "xy_forward_vector_camera=" << conv(obj.xy_forward_vector_camera); }
            oss << "}";
            return oss.str();

    }
    CharacterPhysicsUpdateData string_to_CharacterPhysicsUpdateData(const std::string &s) {
        CharacterPhysicsUpdateData obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return std::stod(s); };
                    obj.dt = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &s) -> ClientInputState {
            ClientInputState obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return s == "true"; };
                    obj.forward_pressed = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return s == "true"; };
                    obj.back_pressed = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return s == "true"; };
                    obj.right_pressed = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return s == "true"; };
                    obj.left_pressed = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return s == "true"; };
                    obj.jump_pressed = conv(value_str);
                }
            }
            return obj;
        };
                    obj.client_input_state = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) {   std::regex r(R"(\s*\(?\s*([-+]?[0-9]*\.?[0-9]+)\s*,\s*([-+]?[0-9]*\.?[0-9]+)\s*,\s*([-+]?[0-9]*\.?[0-9]+)\s*\)?\s*)");   std::smatch m;   if (std::regex_match(s, m, r)) {     return glm::vec3(std::stof(m[1]), std::stof(m[2]), std::stof(m[3]));   }   throw std::invalid_argument("Invalid glm::vec3 string"); };
                    obj.xy_forward_vector_camera = conv(value_str);
                }
            }
            return obj;

    }
    std::vector<uint8_t> serialize_CharacterPhysicsUpdateData(const CharacterPhysicsUpdateData obj) {
        std::vector<uint8_t> buffer;
            { auto ser = [](const double &v) {   std::vector<uint8_t> buf(sizeof(double));   std::memcpy(buf.data(), &v, sizeof(double));   return buf; };
              auto bytes = ser(obj.dt);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [=](const ClientInputState& obj) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            { auto ser = [](const bool &v) {   std::vector<uint8_t> buf(1);   buf[0] = v ? 1 : 0;   return buf; };
              auto bytes = ser(obj.forward_pressed);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const bool &v) {   std::vector<uint8_t> buf(1);   buf[0] = v ? 1 : 0;   return buf; };
              auto bytes = ser(obj.back_pressed);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const bool &v) {   std::vector<uint8_t> buf(1);   buf[0] = v ? 1 : 0;   return buf; };
              auto bytes = ser(obj.right_pressed);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const bool &v) {   std::vector<uint8_t> buf(1);   buf[0] = v ? 1 : 0;   return buf; };
              auto bytes = ser(obj.left_pressed);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const bool &v) {   std::vector<uint8_t> buf(1);   buf[0] = v ? 1 : 0;   return buf; };
              auto bytes = ser(obj.jump_pressed);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;
        };
              auto bytes = ser(obj.client_input_state);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const glm::vec3 &v) {   std::vector<uint8_t> buf(sizeof(glm::vec3));   std::memcpy(buf.data(), &v, sizeof(glm::vec3));   return buf; };
              auto bytes = ser(obj.xy_forward_vector_camera);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;

    }
    size_t size_when_serialized_CharacterPhysicsUpdateData(const CharacterPhysicsUpdateData obj) {
        size_t total = 0;
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.dt); }
            { auto size_fn = [=](const ClientInputState& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.forward_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.back_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.right_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.left_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.jump_pressed); }
            return total;
        };
              total += size_fn(obj.client_input_state); }
            { auto size_fn = [](const glm::vec3 &v) { return sizeof(glm::vec3); };
              total += size_fn(obj.xy_forward_vector_camera); }
            return total;

    }
    CharacterPhysicsUpdateData deserialize_CharacterPhysicsUpdateData(const std::vector<uint8_t> &buffer) {
        CharacterPhysicsUpdateData obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   double v;   std::memcpy(&v, buf.data(), sizeof(double));   return v; };
              auto size_fn = [](const double &v) { return sizeof(double); };
              size_t len = size_fn(obj.dt);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.dt = deser(slice);
              offset += len;
            }
            { auto deser = [=](const std::vector<uint8_t> &buffer) -> ClientInputState {
            ClientInputState obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   return buf[0] != 0; };
              auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              size_t len = size_fn(obj.forward_pressed);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.forward_pressed = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   return buf[0] != 0; };
              auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              size_t len = size_fn(obj.back_pressed);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.back_pressed = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   return buf[0] != 0; };
              auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              size_t len = size_fn(obj.right_pressed);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.right_pressed = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   return buf[0] != 0; };
              auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              size_t len = size_fn(obj.left_pressed);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.left_pressed = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   return buf[0] != 0; };
              auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              size_t len = size_fn(obj.jump_pressed);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.jump_pressed = deser(slice);
              offset += len;
            }
            return obj;
        };
              auto size_fn = [=](const ClientInputState& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.forward_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.back_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.right_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.left_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.jump_pressed); }
            return total;
        };
              size_t len = size_fn(obj.client_input_state);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.client_input_state = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   glm::vec3 v;   std::memcpy(&v, buf.data(), sizeof(glm::vec3));   return v; };
              auto size_fn = [](const glm::vec3 &v) { return sizeof(glm::vec3); };
              size_t len = size_fn(obj.xy_forward_vector_camera);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.xy_forward_vector_camera = deser(slice);
              offset += len;
            }
            return obj;

    }
    std::string IdTaggedCharacterPhysicsUpdateData_to_string(const IdTaggedCharacterPhysicsUpdateData obj) {
        std::ostringstream oss;
            oss << "{";
            { auto conv = [](const unsigned int &v) { return std::to_string(v); };
              oss << "id=" << conv(obj.id); }
            oss << ", ";
            { auto conv = [=](const CharacterPhysicsUpdateData& obj) -> std::string {
            std::ostringstream oss;
            oss << "{";
            { auto conv = [](const double &v) {  std::ostringstream oss;  oss << std::setprecision(std::numeric_limits<double>::max_digits10) << v;  return oss.str();};
              oss << "dt=" << conv(obj.dt); }
            oss << ", ";
            { auto conv = [=](const ClientInputState& obj) -> std::string {
            std::ostringstream oss;
            oss << "{";
            { auto conv = [](const bool &v) { return v ? "true" : "false"; };
              oss << "forward_pressed=" << conv(obj.forward_pressed); }
            oss << ", ";
            { auto conv = [](const bool &v) { return v ? "true" : "false"; };
              oss << "back_pressed=" << conv(obj.back_pressed); }
            oss << ", ";
            { auto conv = [](const bool &v) { return v ? "true" : "false"; };
              oss << "right_pressed=" << conv(obj.right_pressed); }
            oss << ", ";
            { auto conv = [](const bool &v) { return v ? "true" : "false"; };
              oss << "left_pressed=" << conv(obj.left_pressed); }
            oss << ", ";
            { auto conv = [](const bool &v) { return v ? "true" : "false"; };
              oss << "jump_pressed=" << conv(obj.jump_pressed); }
            oss << "}";
            return oss.str();
        };
              oss << "client_input_state=" << conv(obj.client_input_state); }
            oss << ", ";
            { auto conv = [](const glm::vec3 &v) {  int precision =  std::numeric_limits<float>::max_digits10; std::ostringstream oss; oss << std::fixed << std::setprecision(precision); oss << '(' << v.x << ',' << ' ' << v.y << ',' << ' ' << v.z <<  ')'; return oss.str();};
              oss << "xy_forward_vector_camera=" << conv(obj.xy_forward_vector_camera); }
            oss << "}";
            return oss.str();
        };
              oss << "character_physics_update_data=" << conv(obj.character_physics_update_data); }
            oss << "}";
            return oss.str();

    }
    IdTaggedCharacterPhysicsUpdateData string_to_IdTaggedCharacterPhysicsUpdateData(const std::string &s) {
        IdTaggedCharacterPhysicsUpdateData obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return static_cast<unsigned int>(std::stoul(s)); };
                    obj.id = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &s) -> CharacterPhysicsUpdateData {
            CharacterPhysicsUpdateData obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return std::stod(s); };
                    obj.dt = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &s) -> ClientInputState {
            ClientInputState obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return s == "true"; };
                    obj.forward_pressed = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return s == "true"; };
                    obj.back_pressed = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return s == "true"; };
                    obj.right_pressed = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return s == "true"; };
                    obj.left_pressed = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return s == "true"; };
                    obj.jump_pressed = conv(value_str);
                }
            }
            return obj;
        };
                    obj.client_input_state = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) {   std::regex r(R"(\s*\(?\s*([-+]?[0-9]*\.?[0-9]+)\s*,\s*([-+]?[0-9]*\.?[0-9]+)\s*,\s*([-+]?[0-9]*\.?[0-9]+)\s*\)?\s*)");   std::smatch m;   if (std::regex_match(s, m, r)) {     return glm::vec3(std::stof(m[1]), std::stof(m[2]), std::stof(m[3]));   }   throw std::invalid_argument("Invalid glm::vec3 string"); };
                    obj.xy_forward_vector_camera = conv(value_str);
                }
            }
            return obj;
        };
                    obj.character_physics_update_data = conv(value_str);
                }
            }
            return obj;

    }
    std::vector<uint8_t> serialize_IdTaggedCharacterPhysicsUpdateData(const IdTaggedCharacterPhysicsUpdateData obj) {
        std::vector<uint8_t> buffer;
            { auto ser = [](const unsigned int &v) {   std::vector<uint8_t> buf(sizeof(unsigned int));   std::memcpy(buf.data(), &v, sizeof(unsigned int));   return buf; };
              auto bytes = ser(obj.id);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [=](const CharacterPhysicsUpdateData& obj) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            { auto ser = [](const double &v) {   std::vector<uint8_t> buf(sizeof(double));   std::memcpy(buf.data(), &v, sizeof(double));   return buf; };
              auto bytes = ser(obj.dt);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [=](const ClientInputState& obj) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            { auto ser = [](const bool &v) {   std::vector<uint8_t> buf(1);   buf[0] = v ? 1 : 0;   return buf; };
              auto bytes = ser(obj.forward_pressed);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const bool &v) {   std::vector<uint8_t> buf(1);   buf[0] = v ? 1 : 0;   return buf; };
              auto bytes = ser(obj.back_pressed);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const bool &v) {   std::vector<uint8_t> buf(1);   buf[0] = v ? 1 : 0;   return buf; };
              auto bytes = ser(obj.right_pressed);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const bool &v) {   std::vector<uint8_t> buf(1);   buf[0] = v ? 1 : 0;   return buf; };
              auto bytes = ser(obj.left_pressed);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const bool &v) {   std::vector<uint8_t> buf(1);   buf[0] = v ? 1 : 0;   return buf; };
              auto bytes = ser(obj.jump_pressed);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;
        };
              auto bytes = ser(obj.client_input_state);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const glm::vec3 &v) {   std::vector<uint8_t> buf(sizeof(glm::vec3));   std::memcpy(buf.data(), &v, sizeof(glm::vec3));   return buf; };
              auto bytes = ser(obj.xy_forward_vector_camera);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;
        };
              auto bytes = ser(obj.character_physics_update_data);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;

    }
    size_t size_when_serialized_IdTaggedCharacterPhysicsUpdateData(const IdTaggedCharacterPhysicsUpdateData obj) {
        size_t total = 0;
            { auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              total += size_fn(obj.id); }
            { auto size_fn = [=](const CharacterPhysicsUpdateData& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.dt); }
            { auto size_fn = [=](const ClientInputState& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.forward_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.back_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.right_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.left_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.jump_pressed); }
            return total;
        };
              total += size_fn(obj.client_input_state); }
            { auto size_fn = [](const glm::vec3 &v) { return sizeof(glm::vec3); };
              total += size_fn(obj.xy_forward_vector_camera); }
            return total;
        };
              total += size_fn(obj.character_physics_update_data); }
            return total;

    }
    IdTaggedCharacterPhysicsUpdateData deserialize_IdTaggedCharacterPhysicsUpdateData(const std::vector<uint8_t> &buffer) {
        IdTaggedCharacterPhysicsUpdateData obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   unsigned int v;   std::memcpy(&v, buf.data(), sizeof(unsigned int));   return v; };
              auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              size_t len = size_fn(obj.id);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.id = deser(slice);
              offset += len;
            }
            { auto deser = [=](const std::vector<uint8_t> &buffer) -> CharacterPhysicsUpdateData {
            CharacterPhysicsUpdateData obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   double v;   std::memcpy(&v, buf.data(), sizeof(double));   return v; };
              auto size_fn = [](const double &v) { return sizeof(double); };
              size_t len = size_fn(obj.dt);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.dt = deser(slice);
              offset += len;
            }
            { auto deser = [=](const std::vector<uint8_t> &buffer) -> ClientInputState {
            ClientInputState obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   return buf[0] != 0; };
              auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              size_t len = size_fn(obj.forward_pressed);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.forward_pressed = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   return buf[0] != 0; };
              auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              size_t len = size_fn(obj.back_pressed);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.back_pressed = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   return buf[0] != 0; };
              auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              size_t len = size_fn(obj.right_pressed);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.right_pressed = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   return buf[0] != 0; };
              auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              size_t len = size_fn(obj.left_pressed);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.left_pressed = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   return buf[0] != 0; };
              auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              size_t len = size_fn(obj.jump_pressed);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.jump_pressed = deser(slice);
              offset += len;
            }
            return obj;
        };
              auto size_fn = [=](const ClientInputState& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.forward_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.back_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.right_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.left_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.jump_pressed); }
            return total;
        };
              size_t len = size_fn(obj.client_input_state);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.client_input_state = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   glm::vec3 v;   std::memcpy(&v, buf.data(), sizeof(glm::vec3));   return v; };
              auto size_fn = [](const glm::vec3 &v) { return sizeof(glm::vec3); };
              size_t len = size_fn(obj.xy_forward_vector_camera);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.xy_forward_vector_camera = deser(slice);
              offset += len;
            }
            return obj;
        };
              auto size_fn = [=](const CharacterPhysicsUpdateData& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.dt); }
            { auto size_fn = [=](const ClientInputState& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.forward_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.back_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.right_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.left_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.jump_pressed); }
            return total;
        };
              total += size_fn(obj.client_input_state); }
            { auto size_fn = [](const glm::vec3 &v) { return sizeof(glm::vec3); };
              total += size_fn(obj.xy_forward_vector_camera); }
            return total;
        };
              size_t len = size_fn(obj.character_physics_update_data);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.character_physics_update_data = deser(slice);
              offset += len;
            }
            return obj;

    }
    std::string CharacterCameraState_to_string(const CharacterCameraState obj) {
        std::ostringstream oss;
            oss << "{";
            { auto conv = [](const double &v) {  std::ostringstream oss;  oss << std::setprecision(std::numeric_limits<double>::max_digits10) << v;  return oss.str();};
              oss << "yaw=" << conv(obj.yaw); }
            oss << ", ";
            { auto conv = [](const double &v) {  std::ostringstream oss;  oss << std::setprecision(std::numeric_limits<double>::max_digits10) << v;  return oss.str();};
              oss << "pitch=" << conv(obj.pitch); }
            oss << ", ";
            { auto conv = [](const double &v) {  std::ostringstream oss;  oss << std::setprecision(std::numeric_limits<double>::max_digits10) << v;  return oss.str();};
              oss << "last_mouse_position_x=" << conv(obj.last_mouse_position_x); }
            oss << ", ";
            { auto conv = [](const double &v) {  std::ostringstream oss;  oss << std::setprecision(std::numeric_limits<double>::max_digits10) << v;  return oss.str();};
              oss << "last_mouse_position_y=" << conv(obj.last_mouse_position_y); }
            oss << "}";
            return oss.str();

    }
    CharacterCameraState string_to_CharacterCameraState(const std::string &s) {
        CharacterCameraState obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return std::stod(s); };
                    obj.yaw = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return std::stod(s); };
                    obj.pitch = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return std::stod(s); };
                    obj.last_mouse_position_x = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return std::stod(s); };
                    obj.last_mouse_position_y = conv(value_str);
                }
            }
            return obj;

    }
    std::vector<uint8_t> serialize_CharacterCameraState(const CharacterCameraState obj) {
        std::vector<uint8_t> buffer;
            { auto ser = [](const double &v) {   std::vector<uint8_t> buf(sizeof(double));   std::memcpy(buf.data(), &v, sizeof(double));   return buf; };
              auto bytes = ser(obj.yaw);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const double &v) {   std::vector<uint8_t> buf(sizeof(double));   std::memcpy(buf.data(), &v, sizeof(double));   return buf; };
              auto bytes = ser(obj.pitch);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const double &v) {   std::vector<uint8_t> buf(sizeof(double));   std::memcpy(buf.data(), &v, sizeof(double));   return buf; };
              auto bytes = ser(obj.last_mouse_position_x);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const double &v) {   std::vector<uint8_t> buf(sizeof(double));   std::memcpy(buf.data(), &v, sizeof(double));   return buf; };
              auto bytes = ser(obj.last_mouse_position_y);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;

    }
    size_t size_when_serialized_CharacterCameraState(const CharacterCameraState obj) {
        size_t total = 0;
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.yaw); }
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.pitch); }
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.last_mouse_position_x); }
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.last_mouse_position_y); }
            return total;

    }
    CharacterCameraState deserialize_CharacterCameraState(const std::vector<uint8_t> &buffer) {
        CharacterCameraState obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   double v;   std::memcpy(&v, buf.data(), sizeof(double));   return v; };
              auto size_fn = [](const double &v) { return sizeof(double); };
              size_t len = size_fn(obj.yaw);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.yaw = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   double v;   std::memcpy(&v, buf.data(), sizeof(double));   return v; };
              auto size_fn = [](const double &v) { return sizeof(double); };
              size_t len = size_fn(obj.pitch);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.pitch = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   double v;   std::memcpy(&v, buf.data(), sizeof(double));   return v; };
              auto size_fn = [](const double &v) { return sizeof(double); };
              size_t len = size_fn(obj.last_mouse_position_x);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.last_mouse_position_x = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   double v;   std::memcpy(&v, buf.data(), sizeof(double));   return v; };
              auto size_fn = [](const double &v) { return sizeof(double); };
              size_t len = size_fn(obj.last_mouse_position_y);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.last_mouse_position_y = deser(slice);
              offset += len;
            }
            return obj;

    }
    std::string IdTaggedCharacterCameraState_to_string(const IdTaggedCharacterCameraState obj) {
        std::ostringstream oss;
            oss << "{";
            { auto conv = [](const unsigned int &v) { return std::to_string(v); };
              oss << "id_of_last_update_data_used_to_produce_this_state=" << conv(obj.id_of_last_update_data_used_to_produce_this_state); }
            oss << ", ";
            { auto conv = [=](const CharacterCameraState& obj) -> std::string {
            std::ostringstream oss;
            oss << "{";
            { auto conv = [](const double &v) {  std::ostringstream oss;  oss << std::setprecision(std::numeric_limits<double>::max_digits10) << v;  return oss.str();};
              oss << "yaw=" << conv(obj.yaw); }
            oss << ", ";
            { auto conv = [](const double &v) {  std::ostringstream oss;  oss << std::setprecision(std::numeric_limits<double>::max_digits10) << v;  return oss.str();};
              oss << "pitch=" << conv(obj.pitch); }
            oss << ", ";
            { auto conv = [](const double &v) {  std::ostringstream oss;  oss << std::setprecision(std::numeric_limits<double>::max_digits10) << v;  return oss.str();};
              oss << "last_mouse_position_x=" << conv(obj.last_mouse_position_x); }
            oss << ", ";
            { auto conv = [](const double &v) {  std::ostringstream oss;  oss << std::setprecision(std::numeric_limits<double>::max_digits10) << v;  return oss.str();};
              oss << "last_mouse_position_y=" << conv(obj.last_mouse_position_y); }
            oss << "}";
            return oss.str();
        };
              oss << "character_camera_state=" << conv(obj.character_camera_state); }
            oss << "}";
            return oss.str();

    }
    IdTaggedCharacterCameraState string_to_IdTaggedCharacterCameraState(const std::string &s) {
        IdTaggedCharacterCameraState obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return static_cast<unsigned int>(std::stoul(s)); };
                    obj.id_of_last_update_data_used_to_produce_this_state = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &s) -> CharacterCameraState {
            CharacterCameraState obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return std::stod(s); };
                    obj.yaw = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return std::stod(s); };
                    obj.pitch = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return std::stod(s); };
                    obj.last_mouse_position_x = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return std::stod(s); };
                    obj.last_mouse_position_y = conv(value_str);
                }
            }
            return obj;
        };
                    obj.character_camera_state = conv(value_str);
                }
            }
            return obj;

    }
    std::vector<uint8_t> serialize_IdTaggedCharacterCameraState(const IdTaggedCharacterCameraState obj) {
        std::vector<uint8_t> buffer;
            { auto ser = [](const unsigned int &v) {   std::vector<uint8_t> buf(sizeof(unsigned int));   std::memcpy(buf.data(), &v, sizeof(unsigned int));   return buf; };
              auto bytes = ser(obj.id_of_last_update_data_used_to_produce_this_state);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [=](const CharacterCameraState& obj) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            { auto ser = [](const double &v) {   std::vector<uint8_t> buf(sizeof(double));   std::memcpy(buf.data(), &v, sizeof(double));   return buf; };
              auto bytes = ser(obj.yaw);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const double &v) {   std::vector<uint8_t> buf(sizeof(double));   std::memcpy(buf.data(), &v, sizeof(double));   return buf; };
              auto bytes = ser(obj.pitch);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const double &v) {   std::vector<uint8_t> buf(sizeof(double));   std::memcpy(buf.data(), &v, sizeof(double));   return buf; };
              auto bytes = ser(obj.last_mouse_position_x);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const double &v) {   std::vector<uint8_t> buf(sizeof(double));   std::memcpy(buf.data(), &v, sizeof(double));   return buf; };
              auto bytes = ser(obj.last_mouse_position_y);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;
        };
              auto bytes = ser(obj.character_camera_state);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;

    }
    size_t size_when_serialized_IdTaggedCharacterCameraState(const IdTaggedCharacterCameraState obj) {
        size_t total = 0;
            { auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              total += size_fn(obj.id_of_last_update_data_used_to_produce_this_state); }
            { auto size_fn = [=](const CharacterCameraState& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.yaw); }
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.pitch); }
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.last_mouse_position_x); }
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.last_mouse_position_y); }
            return total;
        };
              total += size_fn(obj.character_camera_state); }
            return total;

    }
    IdTaggedCharacterCameraState deserialize_IdTaggedCharacterCameraState(const std::vector<uint8_t> &buffer) {
        IdTaggedCharacterCameraState obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   unsigned int v;   std::memcpy(&v, buf.data(), sizeof(unsigned int));   return v; };
              auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              size_t len = size_fn(obj.id_of_last_update_data_used_to_produce_this_state);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.id_of_last_update_data_used_to_produce_this_state = deser(slice);
              offset += len;
            }
            { auto deser = [=](const std::vector<uint8_t> &buffer) -> CharacterCameraState {
            CharacterCameraState obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   double v;   std::memcpy(&v, buf.data(), sizeof(double));   return v; };
              auto size_fn = [](const double &v) { return sizeof(double); };
              size_t len = size_fn(obj.yaw);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.yaw = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   double v;   std::memcpy(&v, buf.data(), sizeof(double));   return v; };
              auto size_fn = [](const double &v) { return sizeof(double); };
              size_t len = size_fn(obj.pitch);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.pitch = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   double v;   std::memcpy(&v, buf.data(), sizeof(double));   return v; };
              auto size_fn = [](const double &v) { return sizeof(double); };
              size_t len = size_fn(obj.last_mouse_position_x);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.last_mouse_position_x = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   double v;   std::memcpy(&v, buf.data(), sizeof(double));   return v; };
              auto size_fn = [](const double &v) { return sizeof(double); };
              size_t len = size_fn(obj.last_mouse_position_y);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.last_mouse_position_y = deser(slice);
              offset += len;
            }
            return obj;
        };
              auto size_fn = [=](const CharacterCameraState& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.yaw); }
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.pitch); }
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.last_mouse_position_x); }
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.last_mouse_position_y); }
            return total;
        };
              size_t len = size_fn(obj.character_camera_state);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.character_camera_state = deser(slice);
              offset += len;
            }
            return obj;

    }
    std::string CharacterCameraUpdateData_to_string(const CharacterCameraUpdateData obj) {
        std::ostringstream oss;
            oss << "{";
            { auto conv = [](const double &v) {  std::ostringstream oss;  oss << std::setprecision(std::numeric_limits<double>::max_digits10) << v;  return oss.str();};
              oss << "mouse_position_x=" << conv(obj.mouse_position_x); }
            oss << ", ";
            { auto conv = [](const double &v) {  std::ostringstream oss;  oss << std::setprecision(std::numeric_limits<double>::max_digits10) << v;  return oss.str();};
              oss << "mouse_position_y=" << conv(obj.mouse_position_y); }
            oss << ", ";
            { auto conv = [](const double &v) {  std::ostringstream oss;  oss << std::setprecision(std::numeric_limits<double>::max_digits10) << v;  return oss.str();};
              oss << "sensitivity=" << conv(obj.sensitivity); }
            oss << "}";
            return oss.str();

    }
    CharacterCameraUpdateData string_to_CharacterCameraUpdateData(const std::string &s) {
        CharacterCameraUpdateData obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return std::stod(s); };
                    obj.mouse_position_x = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return std::stod(s); };
                    obj.mouse_position_y = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return std::stod(s); };
                    obj.sensitivity = conv(value_str);
                }
            }
            return obj;

    }
    std::vector<uint8_t> serialize_CharacterCameraUpdateData(const CharacterCameraUpdateData obj) {
        std::vector<uint8_t> buffer;
            { auto ser = [](const double &v) {   std::vector<uint8_t> buf(sizeof(double));   std::memcpy(buf.data(), &v, sizeof(double));   return buf; };
              auto bytes = ser(obj.mouse_position_x);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const double &v) {   std::vector<uint8_t> buf(sizeof(double));   std::memcpy(buf.data(), &v, sizeof(double));   return buf; };
              auto bytes = ser(obj.mouse_position_y);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const double &v) {   std::vector<uint8_t> buf(sizeof(double));   std::memcpy(buf.data(), &v, sizeof(double));   return buf; };
              auto bytes = ser(obj.sensitivity);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;

    }
    size_t size_when_serialized_CharacterCameraUpdateData(const CharacterCameraUpdateData obj) {
        size_t total = 0;
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.mouse_position_x); }
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.mouse_position_y); }
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.sensitivity); }
            return total;

    }
    CharacterCameraUpdateData deserialize_CharacterCameraUpdateData(const std::vector<uint8_t> &buffer) {
        CharacterCameraUpdateData obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   double v;   std::memcpy(&v, buf.data(), sizeof(double));   return v; };
              auto size_fn = [](const double &v) { return sizeof(double); };
              size_t len = size_fn(obj.mouse_position_x);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.mouse_position_x = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   double v;   std::memcpy(&v, buf.data(), sizeof(double));   return v; };
              auto size_fn = [](const double &v) { return sizeof(double); };
              size_t len = size_fn(obj.mouse_position_y);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.mouse_position_y = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   double v;   std::memcpy(&v, buf.data(), sizeof(double));   return v; };
              auto size_fn = [](const double &v) { return sizeof(double); };
              size_t len = size_fn(obj.sensitivity);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.sensitivity = deser(slice);
              offset += len;
            }
            return obj;

    }
    std::string CharacterFiringUpdateData_to_string(const CharacterFiringUpdateData obj) {
        std::ostringstream oss;
            oss << "{";
            { auto conv = [](const bool &v) { return v ? "true" : "false"; };
              oss << "fire_pressed=" << conv(obj.fire_pressed); }
            oss << ", ";
            { auto conv = [=](const std::optional<DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer>& opt) -> std::string {
            if (!opt.has_value()) {
                return "std::nullopt";
            }
        
            auto conversion = [=](const DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer& obj) -> std::string {
            std::ostringstream oss;
            oss << "{";
            { auto conv = [](const unsigned int &v) { return std::to_string(v); };
              oss << "id_of_interpolation_start_game_state_id_for_non_local_character_state=" << conv(obj.id_of_interpolation_start_game_state_id_for_non_local_character_state); }
            oss << ", ";
            { auto conv = [](const unsigned int &v) { return std::to_string(v); };
              oss << "id_of_interpolation_end_game_state_id_for_non_local_character_state=" << conv(obj.id_of_interpolation_end_game_state_id_for_non_local_character_state); }
            oss << ", ";
            { auto conv = [](const double &v) {  std::ostringstream oss;  oss << std::setprecision(std::numeric_limits<double>::max_digits10) << v;  return oss.str();};
              oss << "interpolation_percent_when_fired=" << conv(obj.interpolation_percent_when_fired); }
            oss << "}";
            return oss.str();
        };
            return conversion(*opt);
        };
              oss << "data_to_reconstruct_non_local_character_physics_state_with_entity_interpolation_when_firing_on_server=" << conv(obj.data_to_reconstruct_non_local_character_physics_state_with_entity_interpolation_when_firing_on_server); }
            oss << "}";
            return oss.str();

    }
    CharacterFiringUpdateData string_to_CharacterFiringUpdateData(const std::string &s) {
        CharacterFiringUpdateData obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return s == "true"; };
                    obj.fire_pressed = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &input) -> std::optional<DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer> {
            std::string trimmed = input;
            // Trim whitespace
            trimmed.erase(0, trimmed.find_first_not_of(" \t\n\r"));
            trimmed.erase(trimmed.find_last_not_of(" \t\n\r") + 1);
        
            // Explicit representation of null:
            if (trimmed == "std::nullopt") {
                return std::nullopt;
            }
        
            // Try matching actual value
            std::regex element_re(R"(.*)");
            std::smatch match;
        
            if (std::regex_match(trimmed, match, element_re)) {
                try {
                    auto conversion = [=](const std::string &s) -> DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer {
            DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return static_cast<unsigned int>(std::stoul(s)); };
                    obj.id_of_interpolation_start_game_state_id_for_non_local_character_state = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return static_cast<unsigned int>(std::stoul(s)); };
                    obj.id_of_interpolation_end_game_state_id_for_non_local_character_state = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return std::stod(s); };
                    obj.interpolation_percent_when_fired = conv(value_str);
                }
            }
            return obj;
        };
                    return conversion(trimmed);
                } catch (...) {
                    return std::nullopt;
                }
            }
        
            // Anything else is treated as nullopt
            return std::nullopt;
        };
                    obj.data_to_reconstruct_non_local_character_physics_state_with_entity_interpolation_when_firing_on_server = conv(value_str);
                }
            }
            return obj;

    }
    std::vector<uint8_t> serialize_CharacterFiringUpdateData(const CharacterFiringUpdateData obj) {
        std::vector<uint8_t> buffer;
            { auto ser = [](const bool &v) {   std::vector<uint8_t> buf(1);   buf[0] = v ? 1 : 0;   return buf; };
              auto bytes = ser(obj.fire_pressed);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [=](const std::optional<DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer>& opt) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
        
            // First byte: 0 = nullopt, 1 = value present
            if (!opt.has_value()) {
                buffer.push_back(0);
                return buffer;
            }
        
            buffer.push_back(1); // value present
            auto element_serializer = [=](const DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer& obj) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            { auto ser = [](const unsigned int &v) {   std::vector<uint8_t> buf(sizeof(unsigned int));   std::memcpy(buf.data(), &v, sizeof(unsigned int));   return buf; };
              auto bytes = ser(obj.id_of_interpolation_start_game_state_id_for_non_local_character_state);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const unsigned int &v) {   std::vector<uint8_t> buf(sizeof(unsigned int));   std::memcpy(buf.data(), &v, sizeof(unsigned int));   return buf; };
              auto bytes = ser(obj.id_of_interpolation_end_game_state_id_for_non_local_character_state);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const double &v) {   std::vector<uint8_t> buf(sizeof(double));   std::memcpy(buf.data(), &v, sizeof(double));   return buf; };
              auto bytes = ser(obj.interpolation_percent_when_fired);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;
        };
            auto elem_bytes = element_serializer(*opt);
            buffer.insert(buffer.end(), elem_bytes.begin(), elem_bytes.end());
        
            return buffer;
        };
              auto bytes = ser(obj.data_to_reconstruct_non_local_character_physics_state_with_entity_interpolation_when_firing_on_server);
              size_t len = bytes.size();
              buffer.resize(buffer.size() + sizeof(size_t));
              std::memcpy(buffer.data() + buffer.size() - sizeof(size_t), &len, sizeof(size_t));
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;

    }
    size_t size_when_serialized_CharacterFiringUpdateData(const CharacterFiringUpdateData obj) {
        size_t total = 0;
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.fire_pressed); }
            { auto size_fn = [=](const std::optional<DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer>& opt) -> size_t {
            size_t total_size = 1; // presence flag (1 byte)
        
            if (!opt.has_value()) {
                return total_size; // only the presence flag
            }
        
            // Value is present, delegate to inner type's size function
            auto element_size_func = [=](const DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              total += size_fn(obj.id_of_interpolation_start_game_state_id_for_non_local_character_state); }
            { auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              total += size_fn(obj.id_of_interpolation_end_game_state_id_for_non_local_character_state); }
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.interpolation_percent_when_fired); }
            return total;
        };
            total_size += element_size_func(*opt);
        
            return total_size;
        };
              total += sizeof(size_t); // length prefix
              total += size_fn(obj.data_to_reconstruct_non_local_character_physics_state_with_entity_interpolation_when_firing_on_server); }
            return total;

    }
    CharacterFiringUpdateData deserialize_CharacterFiringUpdateData(const std::vector<uint8_t> &buffer) {
        CharacterFiringUpdateData obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   return buf[0] != 0; };
              auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              size_t len = size_fn(obj.fire_pressed);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.fire_pressed = deser(slice);
              offset += len;
            }
            { auto deser = [=](const std::vector<uint8_t>& buffer) -> std::optional<DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer> {
            if (buffer.empty()) return std::nullopt;  // empty buffer
        
            // First byte indicates presence of value
            uint8_t has_value = buffer[0];
            if (has_value == 0) return std::nullopt;
        
            // Value is present, delegate deserialization to inner type
            auto element_deserializer = [=](const std::vector<uint8_t> &buffer) -> DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer {
            DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   unsigned int v;   std::memcpy(&v, buf.data(), sizeof(unsigned int));   return v; };
              auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              size_t len = size_fn(obj.id_of_interpolation_start_game_state_id_for_non_local_character_state);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.id_of_interpolation_start_game_state_id_for_non_local_character_state = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   unsigned int v;   std::memcpy(&v, buf.data(), sizeof(unsigned int));   return v; };
              auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              size_t len = size_fn(obj.id_of_interpolation_end_game_state_id_for_non_local_character_state);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.id_of_interpolation_end_game_state_id_for_non_local_character_state = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   double v;   std::memcpy(&v, buf.data(), sizeof(double));   return v; };
              auto size_fn = [](const double &v) { return sizeof(double); };
              size_t len = size_fn(obj.interpolation_percent_when_fired);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.interpolation_percent_when_fired = deser(slice);
              offset += len;
            }
            return obj;
        };
            std::vector<uint8_t> elem_bytes(buffer.begin() + 1, buffer.end());
            return element_deserializer(elem_bytes);
        };
              if (offset + sizeof(size_t) > buffer.size()) return obj;
              size_t len = 0;
              std::memcpy(&len, buffer.data() + offset, sizeof(size_t));
              offset += sizeof(size_t);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.data_to_reconstruct_non_local_character_physics_state_with_entity_interpolation_when_firing_on_server = deser(slice);
              offset += len;
            }
            return obj;

    }
    std::string IdTaggedCharacterCameraUpdateData_to_string(const IdTaggedCharacterCameraUpdateData obj) {
        std::ostringstream oss;
            oss << "{";
            { auto conv = [](const unsigned int &v) { return std::to_string(v); };
              oss << "id=" << conv(obj.id); }
            oss << ", ";
            { auto conv = [=](const CharacterCameraUpdateData& obj) -> std::string {
            std::ostringstream oss;
            oss << "{";
            { auto conv = [](const double &v) {  std::ostringstream oss;  oss << std::setprecision(std::numeric_limits<double>::max_digits10) << v;  return oss.str();};
              oss << "mouse_position_x=" << conv(obj.mouse_position_x); }
            oss << ", ";
            { auto conv = [](const double &v) {  std::ostringstream oss;  oss << std::setprecision(std::numeric_limits<double>::max_digits10) << v;  return oss.str();};
              oss << "mouse_position_y=" << conv(obj.mouse_position_y); }
            oss << ", ";
            { auto conv = [](const double &v) {  std::ostringstream oss;  oss << std::setprecision(std::numeric_limits<double>::max_digits10) << v;  return oss.str();};
              oss << "sensitivity=" << conv(obj.sensitivity); }
            oss << "}";
            return oss.str();
        };
              oss << "character_camera_update_data=" << conv(obj.character_camera_update_data); }
            oss << "}";
            return oss.str();

    }
    IdTaggedCharacterCameraUpdateData string_to_IdTaggedCharacterCameraUpdateData(const std::string &s) {
        IdTaggedCharacterCameraUpdateData obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return static_cast<unsigned int>(std::stoul(s)); };
                    obj.id = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &s) -> CharacterCameraUpdateData {
            CharacterCameraUpdateData obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return std::stod(s); };
                    obj.mouse_position_x = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return std::stod(s); };
                    obj.mouse_position_y = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return std::stod(s); };
                    obj.sensitivity = conv(value_str);
                }
            }
            return obj;
        };
                    obj.character_camera_update_data = conv(value_str);
                }
            }
            return obj;

    }
    std::vector<uint8_t> serialize_IdTaggedCharacterCameraUpdateData(const IdTaggedCharacterCameraUpdateData obj) {
        std::vector<uint8_t> buffer;
            { auto ser = [](const unsigned int &v) {   std::vector<uint8_t> buf(sizeof(unsigned int));   std::memcpy(buf.data(), &v, sizeof(unsigned int));   return buf; };
              auto bytes = ser(obj.id);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [=](const CharacterCameraUpdateData& obj) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            { auto ser = [](const double &v) {   std::vector<uint8_t> buf(sizeof(double));   std::memcpy(buf.data(), &v, sizeof(double));   return buf; };
              auto bytes = ser(obj.mouse_position_x);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const double &v) {   std::vector<uint8_t> buf(sizeof(double));   std::memcpy(buf.data(), &v, sizeof(double));   return buf; };
              auto bytes = ser(obj.mouse_position_y);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const double &v) {   std::vector<uint8_t> buf(sizeof(double));   std::memcpy(buf.data(), &v, sizeof(double));   return buf; };
              auto bytes = ser(obj.sensitivity);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;
        };
              auto bytes = ser(obj.character_camera_update_data);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;

    }
    size_t size_when_serialized_IdTaggedCharacterCameraUpdateData(const IdTaggedCharacterCameraUpdateData obj) {
        size_t total = 0;
            { auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              total += size_fn(obj.id); }
            { auto size_fn = [=](const CharacterCameraUpdateData& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.mouse_position_x); }
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.mouse_position_y); }
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.sensitivity); }
            return total;
        };
              total += size_fn(obj.character_camera_update_data); }
            return total;

    }
    IdTaggedCharacterCameraUpdateData deserialize_IdTaggedCharacterCameraUpdateData(const std::vector<uint8_t> &buffer) {
        IdTaggedCharacterCameraUpdateData obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   unsigned int v;   std::memcpy(&v, buf.data(), sizeof(unsigned int));   return v; };
              auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              size_t len = size_fn(obj.id);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.id = deser(slice);
              offset += len;
            }
            { auto deser = [=](const std::vector<uint8_t> &buffer) -> CharacterCameraUpdateData {
            CharacterCameraUpdateData obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   double v;   std::memcpy(&v, buf.data(), sizeof(double));   return v; };
              auto size_fn = [](const double &v) { return sizeof(double); };
              size_t len = size_fn(obj.mouse_position_x);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.mouse_position_x = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   double v;   std::memcpy(&v, buf.data(), sizeof(double));   return v; };
              auto size_fn = [](const double &v) { return sizeof(double); };
              size_t len = size_fn(obj.mouse_position_y);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.mouse_position_y = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   double v;   std::memcpy(&v, buf.data(), sizeof(double));   return v; };
              auto size_fn = [](const double &v) { return sizeof(double); };
              size_t len = size_fn(obj.sensitivity);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.sensitivity = deser(slice);
              offset += len;
            }
            return obj;
        };
              auto size_fn = [=](const CharacterCameraUpdateData& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.mouse_position_x); }
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.mouse_position_y); }
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.sensitivity); }
            return total;
        };
              size_t len = size_fn(obj.character_camera_update_data);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.character_camera_update_data = deser(slice);
              offset += len;
            }
            return obj;

    }
    std::string CharacterUpdateData_to_string(const CharacterUpdateData obj) {
        std::ostringstream oss;
            oss << "{";
            { auto conv = [=](const CharacterPhysicsUpdateData& obj) -> std::string {
            std::ostringstream oss;
            oss << "{";
            { auto conv = [](const double &v) {  std::ostringstream oss;  oss << std::setprecision(std::numeric_limits<double>::max_digits10) << v;  return oss.str();};
              oss << "dt=" << conv(obj.dt); }
            oss << ", ";
            { auto conv = [=](const ClientInputState& obj) -> std::string {
            std::ostringstream oss;
            oss << "{";
            { auto conv = [](const bool &v) { return v ? "true" : "false"; };
              oss << "forward_pressed=" << conv(obj.forward_pressed); }
            oss << ", ";
            { auto conv = [](const bool &v) { return v ? "true" : "false"; };
              oss << "back_pressed=" << conv(obj.back_pressed); }
            oss << ", ";
            { auto conv = [](const bool &v) { return v ? "true" : "false"; };
              oss << "right_pressed=" << conv(obj.right_pressed); }
            oss << ", ";
            { auto conv = [](const bool &v) { return v ? "true" : "false"; };
              oss << "left_pressed=" << conv(obj.left_pressed); }
            oss << ", ";
            { auto conv = [](const bool &v) { return v ? "true" : "false"; };
              oss << "jump_pressed=" << conv(obj.jump_pressed); }
            oss << "}";
            return oss.str();
        };
              oss << "client_input_state=" << conv(obj.client_input_state); }
            oss << ", ";
            { auto conv = [](const glm::vec3 &v) {  int precision =  std::numeric_limits<float>::max_digits10; std::ostringstream oss; oss << std::fixed << std::setprecision(precision); oss << '(' << v.x << ',' << ' ' << v.y << ',' << ' ' << v.z <<  ')'; return oss.str();};
              oss << "xy_forward_vector_camera=" << conv(obj.xy_forward_vector_camera); }
            oss << "}";
            return oss.str();
        };
              oss << "character_physics_update_data=" << conv(obj.character_physics_update_data); }
            oss << ", ";
            { auto conv = [=](const CharacterCameraUpdateData& obj) -> std::string {
            std::ostringstream oss;
            oss << "{";
            { auto conv = [](const double &v) {  std::ostringstream oss;  oss << std::setprecision(std::numeric_limits<double>::max_digits10) << v;  return oss.str();};
              oss << "mouse_position_x=" << conv(obj.mouse_position_x); }
            oss << ", ";
            { auto conv = [](const double &v) {  std::ostringstream oss;  oss << std::setprecision(std::numeric_limits<double>::max_digits10) << v;  return oss.str();};
              oss << "mouse_position_y=" << conv(obj.mouse_position_y); }
            oss << ", ";
            { auto conv = [](const double &v) {  std::ostringstream oss;  oss << std::setprecision(std::numeric_limits<double>::max_digits10) << v;  return oss.str();};
              oss << "sensitivity=" << conv(obj.sensitivity); }
            oss << "}";
            return oss.str();
        };
              oss << "character_camera_update_data=" << conv(obj.character_camera_update_data); }
            oss << ", ";
            { auto conv = [=](const CharacterFiringUpdateData& obj) -> std::string {
            std::ostringstream oss;
            oss << "{";
            { auto conv = [](const bool &v) { return v ? "true" : "false"; };
              oss << "fire_pressed=" << conv(obj.fire_pressed); }
            oss << ", ";
            { auto conv = [=](const std::optional<DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer>& opt) -> std::string {
            if (!opt.has_value()) {
                return "std::nullopt";
            }
        
            auto conversion = [=](const DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer& obj) -> std::string {
            std::ostringstream oss;
            oss << "{";
            { auto conv = [](const unsigned int &v) { return std::to_string(v); };
              oss << "id_of_interpolation_start_game_state_id_for_non_local_character_state=" << conv(obj.id_of_interpolation_start_game_state_id_for_non_local_character_state); }
            oss << ", ";
            { auto conv = [](const unsigned int &v) { return std::to_string(v); };
              oss << "id_of_interpolation_end_game_state_id_for_non_local_character_state=" << conv(obj.id_of_interpolation_end_game_state_id_for_non_local_character_state); }
            oss << ", ";
            { auto conv = [](const double &v) {  std::ostringstream oss;  oss << std::setprecision(std::numeric_limits<double>::max_digits10) << v;  return oss.str();};
              oss << "interpolation_percent_when_fired=" << conv(obj.interpolation_percent_when_fired); }
            oss << "}";
            return oss.str();
        };
            return conversion(*opt);
        };
              oss << "data_to_reconstruct_non_local_character_physics_state_with_entity_interpolation_when_firing_on_server=" << conv(obj.data_to_reconstruct_non_local_character_physics_state_with_entity_interpolation_when_firing_on_server); }
            oss << "}";
            return oss.str();
        };
              oss << "character_firing_update_data=" << conv(obj.character_firing_update_data); }
            oss << "}";
            return oss.str();

    }
    CharacterUpdateData string_to_CharacterUpdateData(const std::string &s) {
        CharacterUpdateData obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &s) -> CharacterPhysicsUpdateData {
            CharacterPhysicsUpdateData obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return std::stod(s); };
                    obj.dt = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &s) -> ClientInputState {
            ClientInputState obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return s == "true"; };
                    obj.forward_pressed = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return s == "true"; };
                    obj.back_pressed = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return s == "true"; };
                    obj.right_pressed = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return s == "true"; };
                    obj.left_pressed = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return s == "true"; };
                    obj.jump_pressed = conv(value_str);
                }
            }
            return obj;
        };
                    obj.client_input_state = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) {   std::regex r(R"(\s*\(?\s*([-+]?[0-9]*\.?[0-9]+)\s*,\s*([-+]?[0-9]*\.?[0-9]+)\s*,\s*([-+]?[0-9]*\.?[0-9]+)\s*\)?\s*)");   std::smatch m;   if (std::regex_match(s, m, r)) {     return glm::vec3(std::stof(m[1]), std::stof(m[2]), std::stof(m[3]));   }   throw std::invalid_argument("Invalid glm::vec3 string"); };
                    obj.xy_forward_vector_camera = conv(value_str);
                }
            }
            return obj;
        };
                    obj.character_physics_update_data = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &s) -> CharacterCameraUpdateData {
            CharacterCameraUpdateData obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return std::stod(s); };
                    obj.mouse_position_x = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return std::stod(s); };
                    obj.mouse_position_y = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return std::stod(s); };
                    obj.sensitivity = conv(value_str);
                }
            }
            return obj;
        };
                    obj.character_camera_update_data = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &s) -> CharacterFiringUpdateData {
            CharacterFiringUpdateData obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return s == "true"; };
                    obj.fire_pressed = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &input) -> std::optional<DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer> {
            std::string trimmed = input;
            // Trim whitespace
            trimmed.erase(0, trimmed.find_first_not_of(" \t\n\r"));
            trimmed.erase(trimmed.find_last_not_of(" \t\n\r") + 1);
        
            // Explicit representation of null:
            if (trimmed == "std::nullopt") {
                return std::nullopt;
            }
        
            // Try matching actual value
            std::regex element_re(R"(.*)");
            std::smatch match;
        
            if (std::regex_match(trimmed, match, element_re)) {
                try {
                    auto conversion = [=](const std::string &s) -> DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer {
            DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return static_cast<unsigned int>(std::stoul(s)); };
                    obj.id_of_interpolation_start_game_state_id_for_non_local_character_state = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return static_cast<unsigned int>(std::stoul(s)); };
                    obj.id_of_interpolation_end_game_state_id_for_non_local_character_state = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return std::stod(s); };
                    obj.interpolation_percent_when_fired = conv(value_str);
                }
            }
            return obj;
        };
                    return conversion(trimmed);
                } catch (...) {
                    return std::nullopt;
                }
            }
        
            // Anything else is treated as nullopt
            return std::nullopt;
        };
                    obj.data_to_reconstruct_non_local_character_physics_state_with_entity_interpolation_when_firing_on_server = conv(value_str);
                }
            }
            return obj;
        };
                    obj.character_firing_update_data = conv(value_str);
                }
            }
            return obj;

    }
    std::vector<uint8_t> serialize_CharacterUpdateData(const CharacterUpdateData obj) {
        std::vector<uint8_t> buffer;
            { auto ser = [=](const CharacterPhysicsUpdateData& obj) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            { auto ser = [](const double &v) {   std::vector<uint8_t> buf(sizeof(double));   std::memcpy(buf.data(), &v, sizeof(double));   return buf; };
              auto bytes = ser(obj.dt);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [=](const ClientInputState& obj) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            { auto ser = [](const bool &v) {   std::vector<uint8_t> buf(1);   buf[0] = v ? 1 : 0;   return buf; };
              auto bytes = ser(obj.forward_pressed);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const bool &v) {   std::vector<uint8_t> buf(1);   buf[0] = v ? 1 : 0;   return buf; };
              auto bytes = ser(obj.back_pressed);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const bool &v) {   std::vector<uint8_t> buf(1);   buf[0] = v ? 1 : 0;   return buf; };
              auto bytes = ser(obj.right_pressed);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const bool &v) {   std::vector<uint8_t> buf(1);   buf[0] = v ? 1 : 0;   return buf; };
              auto bytes = ser(obj.left_pressed);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const bool &v) {   std::vector<uint8_t> buf(1);   buf[0] = v ? 1 : 0;   return buf; };
              auto bytes = ser(obj.jump_pressed);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;
        };
              auto bytes = ser(obj.client_input_state);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const glm::vec3 &v) {   std::vector<uint8_t> buf(sizeof(glm::vec3));   std::memcpy(buf.data(), &v, sizeof(glm::vec3));   return buf; };
              auto bytes = ser(obj.xy_forward_vector_camera);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;
        };
              auto bytes = ser(obj.character_physics_update_data);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [=](const CharacterCameraUpdateData& obj) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            { auto ser = [](const double &v) {   std::vector<uint8_t> buf(sizeof(double));   std::memcpy(buf.data(), &v, sizeof(double));   return buf; };
              auto bytes = ser(obj.mouse_position_x);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const double &v) {   std::vector<uint8_t> buf(sizeof(double));   std::memcpy(buf.data(), &v, sizeof(double));   return buf; };
              auto bytes = ser(obj.mouse_position_y);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const double &v) {   std::vector<uint8_t> buf(sizeof(double));   std::memcpy(buf.data(), &v, sizeof(double));   return buf; };
              auto bytes = ser(obj.sensitivity);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;
        };
              auto bytes = ser(obj.character_camera_update_data);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [=](const CharacterFiringUpdateData& obj) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            { auto ser = [](const bool &v) {   std::vector<uint8_t> buf(1);   buf[0] = v ? 1 : 0;   return buf; };
              auto bytes = ser(obj.fire_pressed);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [=](const std::optional<DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer>& opt) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
        
            // First byte: 0 = nullopt, 1 = value present
            if (!opt.has_value()) {
                buffer.push_back(0);
                return buffer;
            }
        
            buffer.push_back(1); // value present
            auto element_serializer = [=](const DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer& obj) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            { auto ser = [](const unsigned int &v) {   std::vector<uint8_t> buf(sizeof(unsigned int));   std::memcpy(buf.data(), &v, sizeof(unsigned int));   return buf; };
              auto bytes = ser(obj.id_of_interpolation_start_game_state_id_for_non_local_character_state);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const unsigned int &v) {   std::vector<uint8_t> buf(sizeof(unsigned int));   std::memcpy(buf.data(), &v, sizeof(unsigned int));   return buf; };
              auto bytes = ser(obj.id_of_interpolation_end_game_state_id_for_non_local_character_state);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const double &v) {   std::vector<uint8_t> buf(sizeof(double));   std::memcpy(buf.data(), &v, sizeof(double));   return buf; };
              auto bytes = ser(obj.interpolation_percent_when_fired);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;
        };
            auto elem_bytes = element_serializer(*opt);
            buffer.insert(buffer.end(), elem_bytes.begin(), elem_bytes.end());
        
            return buffer;
        };
              auto bytes = ser(obj.data_to_reconstruct_non_local_character_physics_state_with_entity_interpolation_when_firing_on_server);
              size_t len = bytes.size();
              buffer.resize(buffer.size() + sizeof(size_t));
              std::memcpy(buffer.data() + buffer.size() - sizeof(size_t), &len, sizeof(size_t));
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;
        };
              auto bytes = ser(obj.character_firing_update_data);
              size_t len = bytes.size();
              buffer.resize(buffer.size() + sizeof(size_t));
              std::memcpy(buffer.data() + buffer.size() - sizeof(size_t), &len, sizeof(size_t));
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;

    }
    size_t size_when_serialized_CharacterUpdateData(const CharacterUpdateData obj) {
        size_t total = 0;
            { auto size_fn = [=](const CharacterPhysicsUpdateData& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.dt); }
            { auto size_fn = [=](const ClientInputState& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.forward_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.back_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.right_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.left_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.jump_pressed); }
            return total;
        };
              total += size_fn(obj.client_input_state); }
            { auto size_fn = [](const glm::vec3 &v) { return sizeof(glm::vec3); };
              total += size_fn(obj.xy_forward_vector_camera); }
            return total;
        };
              total += size_fn(obj.character_physics_update_data); }
            { auto size_fn = [=](const CharacterCameraUpdateData& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.mouse_position_x); }
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.mouse_position_y); }
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.sensitivity); }
            return total;
        };
              total += size_fn(obj.character_camera_update_data); }
            { auto size_fn = [=](const CharacterFiringUpdateData& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.fire_pressed); }
            { auto size_fn = [=](const std::optional<DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer>& opt) -> size_t {
            size_t total_size = 1; // presence flag (1 byte)
        
            if (!opt.has_value()) {
                return total_size; // only the presence flag
            }
        
            // Value is present, delegate to inner type's size function
            auto element_size_func = [=](const DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              total += size_fn(obj.id_of_interpolation_start_game_state_id_for_non_local_character_state); }
            { auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              total += size_fn(obj.id_of_interpolation_end_game_state_id_for_non_local_character_state); }
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.interpolation_percent_when_fired); }
            return total;
        };
            total_size += element_size_func(*opt);
        
            return total_size;
        };
              total += sizeof(size_t); // length prefix
              total += size_fn(obj.data_to_reconstruct_non_local_character_physics_state_with_entity_interpolation_when_firing_on_server); }
            return total;
        };
              total += sizeof(size_t); // length prefix
              total += size_fn(obj.character_firing_update_data); }
            return total;

    }
    CharacterUpdateData deserialize_CharacterUpdateData(const std::vector<uint8_t> &buffer) {
        CharacterUpdateData obj;
            size_t offset = 0;
            { auto deser = [=](const std::vector<uint8_t> &buffer) -> CharacterPhysicsUpdateData {
            CharacterPhysicsUpdateData obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   double v;   std::memcpy(&v, buf.data(), sizeof(double));   return v; };
              auto size_fn = [](const double &v) { return sizeof(double); };
              size_t len = size_fn(obj.dt);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.dt = deser(slice);
              offset += len;
            }
            { auto deser = [=](const std::vector<uint8_t> &buffer) -> ClientInputState {
            ClientInputState obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   return buf[0] != 0; };
              auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              size_t len = size_fn(obj.forward_pressed);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.forward_pressed = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   return buf[0] != 0; };
              auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              size_t len = size_fn(obj.back_pressed);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.back_pressed = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   return buf[0] != 0; };
              auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              size_t len = size_fn(obj.right_pressed);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.right_pressed = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   return buf[0] != 0; };
              auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              size_t len = size_fn(obj.left_pressed);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.left_pressed = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   return buf[0] != 0; };
              auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              size_t len = size_fn(obj.jump_pressed);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.jump_pressed = deser(slice);
              offset += len;
            }
            return obj;
        };
              auto size_fn = [=](const ClientInputState& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.forward_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.back_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.right_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.left_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.jump_pressed); }
            return total;
        };
              size_t len = size_fn(obj.client_input_state);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.client_input_state = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   glm::vec3 v;   std::memcpy(&v, buf.data(), sizeof(glm::vec3));   return v; };
              auto size_fn = [](const glm::vec3 &v) { return sizeof(glm::vec3); };
              size_t len = size_fn(obj.xy_forward_vector_camera);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.xy_forward_vector_camera = deser(slice);
              offset += len;
            }
            return obj;
        };
              auto size_fn = [=](const CharacterPhysicsUpdateData& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.dt); }
            { auto size_fn = [=](const ClientInputState& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.forward_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.back_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.right_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.left_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.jump_pressed); }
            return total;
        };
              total += size_fn(obj.client_input_state); }
            { auto size_fn = [](const glm::vec3 &v) { return sizeof(glm::vec3); };
              total += size_fn(obj.xy_forward_vector_camera); }
            return total;
        };
              size_t len = size_fn(obj.character_physics_update_data);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.character_physics_update_data = deser(slice);
              offset += len;
            }
            { auto deser = [=](const std::vector<uint8_t> &buffer) -> CharacterCameraUpdateData {
            CharacterCameraUpdateData obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   double v;   std::memcpy(&v, buf.data(), sizeof(double));   return v; };
              auto size_fn = [](const double &v) { return sizeof(double); };
              size_t len = size_fn(obj.mouse_position_x);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.mouse_position_x = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   double v;   std::memcpy(&v, buf.data(), sizeof(double));   return v; };
              auto size_fn = [](const double &v) { return sizeof(double); };
              size_t len = size_fn(obj.mouse_position_y);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.mouse_position_y = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   double v;   std::memcpy(&v, buf.data(), sizeof(double));   return v; };
              auto size_fn = [](const double &v) { return sizeof(double); };
              size_t len = size_fn(obj.sensitivity);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.sensitivity = deser(slice);
              offset += len;
            }
            return obj;
        };
              auto size_fn = [=](const CharacterCameraUpdateData& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.mouse_position_x); }
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.mouse_position_y); }
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.sensitivity); }
            return total;
        };
              size_t len = size_fn(obj.character_camera_update_data);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.character_camera_update_data = deser(slice);
              offset += len;
            }
            { auto deser = [=](const std::vector<uint8_t> &buffer) -> CharacterFiringUpdateData {
            CharacterFiringUpdateData obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   return buf[0] != 0; };
              auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              size_t len = size_fn(obj.fire_pressed);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.fire_pressed = deser(slice);
              offset += len;
            }
            { auto deser = [=](const std::vector<uint8_t>& buffer) -> std::optional<DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer> {
            if (buffer.empty()) return std::nullopt;  // empty buffer
        
            // First byte indicates presence of value
            uint8_t has_value = buffer[0];
            if (has_value == 0) return std::nullopt;
        
            // Value is present, delegate deserialization to inner type
            auto element_deserializer = [=](const std::vector<uint8_t> &buffer) -> DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer {
            DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   unsigned int v;   std::memcpy(&v, buf.data(), sizeof(unsigned int));   return v; };
              auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              size_t len = size_fn(obj.id_of_interpolation_start_game_state_id_for_non_local_character_state);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.id_of_interpolation_start_game_state_id_for_non_local_character_state = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   unsigned int v;   std::memcpy(&v, buf.data(), sizeof(unsigned int));   return v; };
              auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              size_t len = size_fn(obj.id_of_interpolation_end_game_state_id_for_non_local_character_state);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.id_of_interpolation_end_game_state_id_for_non_local_character_state = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   double v;   std::memcpy(&v, buf.data(), sizeof(double));   return v; };
              auto size_fn = [](const double &v) { return sizeof(double); };
              size_t len = size_fn(obj.interpolation_percent_when_fired);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.interpolation_percent_when_fired = deser(slice);
              offset += len;
            }
            return obj;
        };
            std::vector<uint8_t> elem_bytes(buffer.begin() + 1, buffer.end());
            return element_deserializer(elem_bytes);
        };
              if (offset + sizeof(size_t) > buffer.size()) return obj;
              size_t len = 0;
              std::memcpy(&len, buffer.data() + offset, sizeof(size_t));
              offset += sizeof(size_t);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.data_to_reconstruct_non_local_character_physics_state_with_entity_interpolation_when_firing_on_server = deser(slice);
              offset += len;
            }
            return obj;
        };
              if (offset + sizeof(size_t) > buffer.size()) return obj;
              size_t len = 0;
              std::memcpy(&len, buffer.data() + offset, sizeof(size_t));
              offset += sizeof(size_t);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.character_firing_update_data = deser(slice);
              offset += len;
            }
            return obj;

    }
    std::string IdTaggedCharacterUpdateData_to_string(const IdTaggedCharacterUpdateData obj) {
        std::ostringstream oss;
            oss << "{";
            { auto conv = [](const unsigned int &v) { return std::to_string(v); };
              oss << "id=" << conv(obj.id); }
            oss << ", ";
            { auto conv = [=](const CharacterUpdateData& obj) -> std::string {
            std::ostringstream oss;
            oss << "{";
            { auto conv = [=](const CharacterPhysicsUpdateData& obj) -> std::string {
            std::ostringstream oss;
            oss << "{";
            { auto conv = [](const double &v) {  std::ostringstream oss;  oss << std::setprecision(std::numeric_limits<double>::max_digits10) << v;  return oss.str();};
              oss << "dt=" << conv(obj.dt); }
            oss << ", ";
            { auto conv = [=](const ClientInputState& obj) -> std::string {
            std::ostringstream oss;
            oss << "{";
            { auto conv = [](const bool &v) { return v ? "true" : "false"; };
              oss << "forward_pressed=" << conv(obj.forward_pressed); }
            oss << ", ";
            { auto conv = [](const bool &v) { return v ? "true" : "false"; };
              oss << "back_pressed=" << conv(obj.back_pressed); }
            oss << ", ";
            { auto conv = [](const bool &v) { return v ? "true" : "false"; };
              oss << "right_pressed=" << conv(obj.right_pressed); }
            oss << ", ";
            { auto conv = [](const bool &v) { return v ? "true" : "false"; };
              oss << "left_pressed=" << conv(obj.left_pressed); }
            oss << ", ";
            { auto conv = [](const bool &v) { return v ? "true" : "false"; };
              oss << "jump_pressed=" << conv(obj.jump_pressed); }
            oss << "}";
            return oss.str();
        };
              oss << "client_input_state=" << conv(obj.client_input_state); }
            oss << ", ";
            { auto conv = [](const glm::vec3 &v) {  int precision =  std::numeric_limits<float>::max_digits10; std::ostringstream oss; oss << std::fixed << std::setprecision(precision); oss << '(' << v.x << ',' << ' ' << v.y << ',' << ' ' << v.z <<  ')'; return oss.str();};
              oss << "xy_forward_vector_camera=" << conv(obj.xy_forward_vector_camera); }
            oss << "}";
            return oss.str();
        };
              oss << "character_physics_update_data=" << conv(obj.character_physics_update_data); }
            oss << ", ";
            { auto conv = [=](const CharacterCameraUpdateData& obj) -> std::string {
            std::ostringstream oss;
            oss << "{";
            { auto conv = [](const double &v) {  std::ostringstream oss;  oss << std::setprecision(std::numeric_limits<double>::max_digits10) << v;  return oss.str();};
              oss << "mouse_position_x=" << conv(obj.mouse_position_x); }
            oss << ", ";
            { auto conv = [](const double &v) {  std::ostringstream oss;  oss << std::setprecision(std::numeric_limits<double>::max_digits10) << v;  return oss.str();};
              oss << "mouse_position_y=" << conv(obj.mouse_position_y); }
            oss << ", ";
            { auto conv = [](const double &v) {  std::ostringstream oss;  oss << std::setprecision(std::numeric_limits<double>::max_digits10) << v;  return oss.str();};
              oss << "sensitivity=" << conv(obj.sensitivity); }
            oss << "}";
            return oss.str();
        };
              oss << "character_camera_update_data=" << conv(obj.character_camera_update_data); }
            oss << ", ";
            { auto conv = [=](const CharacterFiringUpdateData& obj) -> std::string {
            std::ostringstream oss;
            oss << "{";
            { auto conv = [](const bool &v) { return v ? "true" : "false"; };
              oss << "fire_pressed=" << conv(obj.fire_pressed); }
            oss << ", ";
            { auto conv = [=](const std::optional<DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer>& opt) -> std::string {
            if (!opt.has_value()) {
                return "std::nullopt";
            }
        
            auto conversion = [=](const DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer& obj) -> std::string {
            std::ostringstream oss;
            oss << "{";
            { auto conv = [](const unsigned int &v) { return std::to_string(v); };
              oss << "id_of_interpolation_start_game_state_id_for_non_local_character_state=" << conv(obj.id_of_interpolation_start_game_state_id_for_non_local_character_state); }
            oss << ", ";
            { auto conv = [](const unsigned int &v) { return std::to_string(v); };
              oss << "id_of_interpolation_end_game_state_id_for_non_local_character_state=" << conv(obj.id_of_interpolation_end_game_state_id_for_non_local_character_state); }
            oss << ", ";
            { auto conv = [](const double &v) {  std::ostringstream oss;  oss << std::setprecision(std::numeric_limits<double>::max_digits10) << v;  return oss.str();};
              oss << "interpolation_percent_when_fired=" << conv(obj.interpolation_percent_when_fired); }
            oss << "}";
            return oss.str();
        };
            return conversion(*opt);
        };
              oss << "data_to_reconstruct_non_local_character_physics_state_with_entity_interpolation_when_firing_on_server=" << conv(obj.data_to_reconstruct_non_local_character_physics_state_with_entity_interpolation_when_firing_on_server); }
            oss << "}";
            return oss.str();
        };
              oss << "character_firing_update_data=" << conv(obj.character_firing_update_data); }
            oss << "}";
            return oss.str();
        };
              oss << "character_update_data=" << conv(obj.character_update_data); }
            oss << "}";
            return oss.str();

    }
    IdTaggedCharacterUpdateData string_to_IdTaggedCharacterUpdateData(const std::string &s) {
        IdTaggedCharacterUpdateData obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return static_cast<unsigned int>(std::stoul(s)); };
                    obj.id = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &s) -> CharacterUpdateData {
            CharacterUpdateData obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &s) -> CharacterPhysicsUpdateData {
            CharacterPhysicsUpdateData obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return std::stod(s); };
                    obj.dt = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &s) -> ClientInputState {
            ClientInputState obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return s == "true"; };
                    obj.forward_pressed = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return s == "true"; };
                    obj.back_pressed = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return s == "true"; };
                    obj.right_pressed = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return s == "true"; };
                    obj.left_pressed = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return s == "true"; };
                    obj.jump_pressed = conv(value_str);
                }
            }
            return obj;
        };
                    obj.client_input_state = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) {   std::regex r(R"(\s*\(?\s*([-+]?[0-9]*\.?[0-9]+)\s*,\s*([-+]?[0-9]*\.?[0-9]+)\s*,\s*([-+]?[0-9]*\.?[0-9]+)\s*\)?\s*)");   std::smatch m;   if (std::regex_match(s, m, r)) {     return glm::vec3(std::stof(m[1]), std::stof(m[2]), std::stof(m[3]));   }   throw std::invalid_argument("Invalid glm::vec3 string"); };
                    obj.xy_forward_vector_camera = conv(value_str);
                }
            }
            return obj;
        };
                    obj.character_physics_update_data = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &s) -> CharacterCameraUpdateData {
            CharacterCameraUpdateData obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return std::stod(s); };
                    obj.mouse_position_x = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return std::stod(s); };
                    obj.mouse_position_y = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return std::stod(s); };
                    obj.sensitivity = conv(value_str);
                }
            }
            return obj;
        };
                    obj.character_camera_update_data = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &s) -> CharacterFiringUpdateData {
            CharacterFiringUpdateData obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return s == "true"; };
                    obj.fire_pressed = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &input) -> std::optional<DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer> {
            std::string trimmed = input;
            // Trim whitespace
            trimmed.erase(0, trimmed.find_first_not_of(" \t\n\r"));
            trimmed.erase(trimmed.find_last_not_of(" \t\n\r") + 1);
        
            // Explicit representation of null:
            if (trimmed == "std::nullopt") {
                return std::nullopt;
            }
        
            // Try matching actual value
            std::regex element_re(R"(.*)");
            std::smatch match;
        
            if (std::regex_match(trimmed, match, element_re)) {
                try {
                    auto conversion = [=](const std::string &s) -> DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer {
            DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return static_cast<unsigned int>(std::stoul(s)); };
                    obj.id_of_interpolation_start_game_state_id_for_non_local_character_state = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return static_cast<unsigned int>(std::stoul(s)); };
                    obj.id_of_interpolation_end_game_state_id_for_non_local_character_state = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return std::stod(s); };
                    obj.interpolation_percent_when_fired = conv(value_str);
                }
            }
            return obj;
        };
                    return conversion(trimmed);
                } catch (...) {
                    return std::nullopt;
                }
            }
        
            // Anything else is treated as nullopt
            return std::nullopt;
        };
                    obj.data_to_reconstruct_non_local_character_physics_state_with_entity_interpolation_when_firing_on_server = conv(value_str);
                }
            }
            return obj;
        };
                    obj.character_firing_update_data = conv(value_str);
                }
            }
            return obj;
        };
                    obj.character_update_data = conv(value_str);
                }
            }
            return obj;

    }
    std::vector<uint8_t> serialize_IdTaggedCharacterUpdateData(const IdTaggedCharacterUpdateData obj) {
        std::vector<uint8_t> buffer;
            { auto ser = [](const unsigned int &v) {   std::vector<uint8_t> buf(sizeof(unsigned int));   std::memcpy(buf.data(), &v, sizeof(unsigned int));   return buf; };
              auto bytes = ser(obj.id);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [=](const CharacterUpdateData& obj) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            { auto ser = [=](const CharacterPhysicsUpdateData& obj) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            { auto ser = [](const double &v) {   std::vector<uint8_t> buf(sizeof(double));   std::memcpy(buf.data(), &v, sizeof(double));   return buf; };
              auto bytes = ser(obj.dt);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [=](const ClientInputState& obj) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            { auto ser = [](const bool &v) {   std::vector<uint8_t> buf(1);   buf[0] = v ? 1 : 0;   return buf; };
              auto bytes = ser(obj.forward_pressed);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const bool &v) {   std::vector<uint8_t> buf(1);   buf[0] = v ? 1 : 0;   return buf; };
              auto bytes = ser(obj.back_pressed);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const bool &v) {   std::vector<uint8_t> buf(1);   buf[0] = v ? 1 : 0;   return buf; };
              auto bytes = ser(obj.right_pressed);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const bool &v) {   std::vector<uint8_t> buf(1);   buf[0] = v ? 1 : 0;   return buf; };
              auto bytes = ser(obj.left_pressed);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const bool &v) {   std::vector<uint8_t> buf(1);   buf[0] = v ? 1 : 0;   return buf; };
              auto bytes = ser(obj.jump_pressed);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;
        };
              auto bytes = ser(obj.client_input_state);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const glm::vec3 &v) {   std::vector<uint8_t> buf(sizeof(glm::vec3));   std::memcpy(buf.data(), &v, sizeof(glm::vec3));   return buf; };
              auto bytes = ser(obj.xy_forward_vector_camera);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;
        };
              auto bytes = ser(obj.character_physics_update_data);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [=](const CharacterCameraUpdateData& obj) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            { auto ser = [](const double &v) {   std::vector<uint8_t> buf(sizeof(double));   std::memcpy(buf.data(), &v, sizeof(double));   return buf; };
              auto bytes = ser(obj.mouse_position_x);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const double &v) {   std::vector<uint8_t> buf(sizeof(double));   std::memcpy(buf.data(), &v, sizeof(double));   return buf; };
              auto bytes = ser(obj.mouse_position_y);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const double &v) {   std::vector<uint8_t> buf(sizeof(double));   std::memcpy(buf.data(), &v, sizeof(double));   return buf; };
              auto bytes = ser(obj.sensitivity);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;
        };
              auto bytes = ser(obj.character_camera_update_data);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [=](const CharacterFiringUpdateData& obj) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            { auto ser = [](const bool &v) {   std::vector<uint8_t> buf(1);   buf[0] = v ? 1 : 0;   return buf; };
              auto bytes = ser(obj.fire_pressed);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [=](const std::optional<DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer>& opt) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
        
            // First byte: 0 = nullopt, 1 = value present
            if (!opt.has_value()) {
                buffer.push_back(0);
                return buffer;
            }
        
            buffer.push_back(1); // value present
            auto element_serializer = [=](const DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer& obj) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            { auto ser = [](const unsigned int &v) {   std::vector<uint8_t> buf(sizeof(unsigned int));   std::memcpy(buf.data(), &v, sizeof(unsigned int));   return buf; };
              auto bytes = ser(obj.id_of_interpolation_start_game_state_id_for_non_local_character_state);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const unsigned int &v) {   std::vector<uint8_t> buf(sizeof(unsigned int));   std::memcpy(buf.data(), &v, sizeof(unsigned int));   return buf; };
              auto bytes = ser(obj.id_of_interpolation_end_game_state_id_for_non_local_character_state);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const double &v) {   std::vector<uint8_t> buf(sizeof(double));   std::memcpy(buf.data(), &v, sizeof(double));   return buf; };
              auto bytes = ser(obj.interpolation_percent_when_fired);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;
        };
            auto elem_bytes = element_serializer(*opt);
            buffer.insert(buffer.end(), elem_bytes.begin(), elem_bytes.end());
        
            return buffer;
        };
              auto bytes = ser(obj.data_to_reconstruct_non_local_character_physics_state_with_entity_interpolation_when_firing_on_server);
              size_t len = bytes.size();
              buffer.resize(buffer.size() + sizeof(size_t));
              std::memcpy(buffer.data() + buffer.size() - sizeof(size_t), &len, sizeof(size_t));
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;
        };
              auto bytes = ser(obj.character_firing_update_data);
              size_t len = bytes.size();
              buffer.resize(buffer.size() + sizeof(size_t));
              std::memcpy(buffer.data() + buffer.size() - sizeof(size_t), &len, sizeof(size_t));
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;
        };
              auto bytes = ser(obj.character_update_data);
              size_t len = bytes.size();
              buffer.resize(buffer.size() + sizeof(size_t));
              std::memcpy(buffer.data() + buffer.size() - sizeof(size_t), &len, sizeof(size_t));
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;

    }
    size_t size_when_serialized_IdTaggedCharacterUpdateData(const IdTaggedCharacterUpdateData obj) {
        size_t total = 0;
            { auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              total += size_fn(obj.id); }
            { auto size_fn = [=](const CharacterUpdateData& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [=](const CharacterPhysicsUpdateData& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.dt); }
            { auto size_fn = [=](const ClientInputState& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.forward_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.back_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.right_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.left_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.jump_pressed); }
            return total;
        };
              total += size_fn(obj.client_input_state); }
            { auto size_fn = [](const glm::vec3 &v) { return sizeof(glm::vec3); };
              total += size_fn(obj.xy_forward_vector_camera); }
            return total;
        };
              total += size_fn(obj.character_physics_update_data); }
            { auto size_fn = [=](const CharacterCameraUpdateData& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.mouse_position_x); }
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.mouse_position_y); }
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.sensitivity); }
            return total;
        };
              total += size_fn(obj.character_camera_update_data); }
            { auto size_fn = [=](const CharacterFiringUpdateData& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.fire_pressed); }
            { auto size_fn = [=](const std::optional<DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer>& opt) -> size_t {
            size_t total_size = 1; // presence flag (1 byte)
        
            if (!opt.has_value()) {
                return total_size; // only the presence flag
            }
        
            // Value is present, delegate to inner type's size function
            auto element_size_func = [=](const DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              total += size_fn(obj.id_of_interpolation_start_game_state_id_for_non_local_character_state); }
            { auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              total += size_fn(obj.id_of_interpolation_end_game_state_id_for_non_local_character_state); }
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.interpolation_percent_when_fired); }
            return total;
        };
            total_size += element_size_func(*opt);
        
            return total_size;
        };
              total += sizeof(size_t); // length prefix
              total += size_fn(obj.data_to_reconstruct_non_local_character_physics_state_with_entity_interpolation_when_firing_on_server); }
            return total;
        };
              total += sizeof(size_t); // length prefix
              total += size_fn(obj.character_firing_update_data); }
            return total;
        };
              total += sizeof(size_t); // length prefix
              total += size_fn(obj.character_update_data); }
            return total;

    }
    IdTaggedCharacterUpdateData deserialize_IdTaggedCharacterUpdateData(const std::vector<uint8_t> &buffer) {
        IdTaggedCharacterUpdateData obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   unsigned int v;   std::memcpy(&v, buf.data(), sizeof(unsigned int));   return v; };
              auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              size_t len = size_fn(obj.id);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.id = deser(slice);
              offset += len;
            }
            { auto deser = [=](const std::vector<uint8_t> &buffer) -> CharacterUpdateData {
            CharacterUpdateData obj;
            size_t offset = 0;
            { auto deser = [=](const std::vector<uint8_t> &buffer) -> CharacterPhysicsUpdateData {
            CharacterPhysicsUpdateData obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   double v;   std::memcpy(&v, buf.data(), sizeof(double));   return v; };
              auto size_fn = [](const double &v) { return sizeof(double); };
              size_t len = size_fn(obj.dt);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.dt = deser(slice);
              offset += len;
            }
            { auto deser = [=](const std::vector<uint8_t> &buffer) -> ClientInputState {
            ClientInputState obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   return buf[0] != 0; };
              auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              size_t len = size_fn(obj.forward_pressed);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.forward_pressed = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   return buf[0] != 0; };
              auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              size_t len = size_fn(obj.back_pressed);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.back_pressed = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   return buf[0] != 0; };
              auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              size_t len = size_fn(obj.right_pressed);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.right_pressed = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   return buf[0] != 0; };
              auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              size_t len = size_fn(obj.left_pressed);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.left_pressed = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   return buf[0] != 0; };
              auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              size_t len = size_fn(obj.jump_pressed);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.jump_pressed = deser(slice);
              offset += len;
            }
            return obj;
        };
              auto size_fn = [=](const ClientInputState& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.forward_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.back_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.right_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.left_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.jump_pressed); }
            return total;
        };
              size_t len = size_fn(obj.client_input_state);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.client_input_state = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   glm::vec3 v;   std::memcpy(&v, buf.data(), sizeof(glm::vec3));   return v; };
              auto size_fn = [](const glm::vec3 &v) { return sizeof(glm::vec3); };
              size_t len = size_fn(obj.xy_forward_vector_camera);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.xy_forward_vector_camera = deser(slice);
              offset += len;
            }
            return obj;
        };
              auto size_fn = [=](const CharacterPhysicsUpdateData& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.dt); }
            { auto size_fn = [=](const ClientInputState& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.forward_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.back_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.right_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.left_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.jump_pressed); }
            return total;
        };
              total += size_fn(obj.client_input_state); }
            { auto size_fn = [](const glm::vec3 &v) { return sizeof(glm::vec3); };
              total += size_fn(obj.xy_forward_vector_camera); }
            return total;
        };
              size_t len = size_fn(obj.character_physics_update_data);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.character_physics_update_data = deser(slice);
              offset += len;
            }
            { auto deser = [=](const std::vector<uint8_t> &buffer) -> CharacterCameraUpdateData {
            CharacterCameraUpdateData obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   double v;   std::memcpy(&v, buf.data(), sizeof(double));   return v; };
              auto size_fn = [](const double &v) { return sizeof(double); };
              size_t len = size_fn(obj.mouse_position_x);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.mouse_position_x = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   double v;   std::memcpy(&v, buf.data(), sizeof(double));   return v; };
              auto size_fn = [](const double &v) { return sizeof(double); };
              size_t len = size_fn(obj.mouse_position_y);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.mouse_position_y = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   double v;   std::memcpy(&v, buf.data(), sizeof(double));   return v; };
              auto size_fn = [](const double &v) { return sizeof(double); };
              size_t len = size_fn(obj.sensitivity);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.sensitivity = deser(slice);
              offset += len;
            }
            return obj;
        };
              auto size_fn = [=](const CharacterCameraUpdateData& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.mouse_position_x); }
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.mouse_position_y); }
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.sensitivity); }
            return total;
        };
              size_t len = size_fn(obj.character_camera_update_data);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.character_camera_update_data = deser(slice);
              offset += len;
            }
            { auto deser = [=](const std::vector<uint8_t> &buffer) -> CharacterFiringUpdateData {
            CharacterFiringUpdateData obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   return buf[0] != 0; };
              auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              size_t len = size_fn(obj.fire_pressed);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.fire_pressed = deser(slice);
              offset += len;
            }
            { auto deser = [=](const std::vector<uint8_t>& buffer) -> std::optional<DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer> {
            if (buffer.empty()) return std::nullopt;  // empty buffer
        
            // First byte indicates presence of value
            uint8_t has_value = buffer[0];
            if (has_value == 0) return std::nullopt;
        
            // Value is present, delegate deserialization to inner type
            auto element_deserializer = [=](const std::vector<uint8_t> &buffer) -> DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer {
            DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   unsigned int v;   std::memcpy(&v, buf.data(), sizeof(unsigned int));   return v; };
              auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              size_t len = size_fn(obj.id_of_interpolation_start_game_state_id_for_non_local_character_state);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.id_of_interpolation_start_game_state_id_for_non_local_character_state = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   unsigned int v;   std::memcpy(&v, buf.data(), sizeof(unsigned int));   return v; };
              auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              size_t len = size_fn(obj.id_of_interpolation_end_game_state_id_for_non_local_character_state);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.id_of_interpolation_end_game_state_id_for_non_local_character_state = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   double v;   std::memcpy(&v, buf.data(), sizeof(double));   return v; };
              auto size_fn = [](const double &v) { return sizeof(double); };
              size_t len = size_fn(obj.interpolation_percent_when_fired);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.interpolation_percent_when_fired = deser(slice);
              offset += len;
            }
            return obj;
        };
            std::vector<uint8_t> elem_bytes(buffer.begin() + 1, buffer.end());
            return element_deserializer(elem_bytes);
        };
              if (offset + sizeof(size_t) > buffer.size()) return obj;
              size_t len = 0;
              std::memcpy(&len, buffer.data() + offset, sizeof(size_t));
              offset += sizeof(size_t);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.data_to_reconstruct_non_local_character_physics_state_with_entity_interpolation_when_firing_on_server = deser(slice);
              offset += len;
            }
            return obj;
        };
              if (offset + sizeof(size_t) > buffer.size()) return obj;
              size_t len = 0;
              std::memcpy(&len, buffer.data() + offset, sizeof(size_t));
              offset += sizeof(size_t);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.character_firing_update_data = deser(slice);
              offset += len;
            }
            return obj;
        };
              if (offset + sizeof(size_t) > buffer.size()) return obj;
              size_t len = 0;
              std::memcpy(&len, buffer.data() + offset, sizeof(size_t));
              offset += sizeof(size_t);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.character_update_data = deser(slice);
              offset += len;
            }
            return obj;

    }
    std::string CharacterUpdateDataTimeBundle_to_string(const CharacterUpdateDataTimeBundle obj) {
        std::ostringstream oss;
            oss << "{";
            { auto conv = [=](const std::vector<IdTaggedCharacterUpdateData>& vec) -> std::string {
            std::ostringstream oss;
            oss << "{";
            auto conversion = [=](const IdTaggedCharacterUpdateData& obj) -> std::string {
            std::ostringstream oss;
            oss << "{";
            { auto conv = [](const unsigned int &v) { return std::to_string(v); };
              oss << "id=" << conv(obj.id); }
            oss << ", ";
            { auto conv = [=](const CharacterUpdateData& obj) -> std::string {
            std::ostringstream oss;
            oss << "{";
            { auto conv = [=](const CharacterPhysicsUpdateData& obj) -> std::string {
            std::ostringstream oss;
            oss << "{";
            { auto conv = [](const double &v) {  std::ostringstream oss;  oss << std::setprecision(std::numeric_limits<double>::max_digits10) << v;  return oss.str();};
              oss << "dt=" << conv(obj.dt); }
            oss << ", ";
            { auto conv = [=](const ClientInputState& obj) -> std::string {
            std::ostringstream oss;
            oss << "{";
            { auto conv = [](const bool &v) { return v ? "true" : "false"; };
              oss << "forward_pressed=" << conv(obj.forward_pressed); }
            oss << ", ";
            { auto conv = [](const bool &v) { return v ? "true" : "false"; };
              oss << "back_pressed=" << conv(obj.back_pressed); }
            oss << ", ";
            { auto conv = [](const bool &v) { return v ? "true" : "false"; };
              oss << "right_pressed=" << conv(obj.right_pressed); }
            oss << ", ";
            { auto conv = [](const bool &v) { return v ? "true" : "false"; };
              oss << "left_pressed=" << conv(obj.left_pressed); }
            oss << ", ";
            { auto conv = [](const bool &v) { return v ? "true" : "false"; };
              oss << "jump_pressed=" << conv(obj.jump_pressed); }
            oss << "}";
            return oss.str();
        };
              oss << "client_input_state=" << conv(obj.client_input_state); }
            oss << ", ";
            { auto conv = [](const glm::vec3 &v) {  int precision =  std::numeric_limits<float>::max_digits10; std::ostringstream oss; oss << std::fixed << std::setprecision(precision); oss << '(' << v.x << ',' << ' ' << v.y << ',' << ' ' << v.z <<  ')'; return oss.str();};
              oss << "xy_forward_vector_camera=" << conv(obj.xy_forward_vector_camera); }
            oss << "}";
            return oss.str();
        };
              oss << "character_physics_update_data=" << conv(obj.character_physics_update_data); }
            oss << ", ";
            { auto conv = [=](const CharacterCameraUpdateData& obj) -> std::string {
            std::ostringstream oss;
            oss << "{";
            { auto conv = [](const double &v) {  std::ostringstream oss;  oss << std::setprecision(std::numeric_limits<double>::max_digits10) << v;  return oss.str();};
              oss << "mouse_position_x=" << conv(obj.mouse_position_x); }
            oss << ", ";
            { auto conv = [](const double &v) {  std::ostringstream oss;  oss << std::setprecision(std::numeric_limits<double>::max_digits10) << v;  return oss.str();};
              oss << "mouse_position_y=" << conv(obj.mouse_position_y); }
            oss << ", ";
            { auto conv = [](const double &v) {  std::ostringstream oss;  oss << std::setprecision(std::numeric_limits<double>::max_digits10) << v;  return oss.str();};
              oss << "sensitivity=" << conv(obj.sensitivity); }
            oss << "}";
            return oss.str();
        };
              oss << "character_camera_update_data=" << conv(obj.character_camera_update_data); }
            oss << ", ";
            { auto conv = [=](const CharacterFiringUpdateData& obj) -> std::string {
            std::ostringstream oss;
            oss << "{";
            { auto conv = [](const bool &v) { return v ? "true" : "false"; };
              oss << "fire_pressed=" << conv(obj.fire_pressed); }
            oss << ", ";
            { auto conv = [=](const std::optional<DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer>& opt) -> std::string {
            if (!opt.has_value()) {
                return "std::nullopt";
            }
        
            auto conversion = [=](const DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer& obj) -> std::string {
            std::ostringstream oss;
            oss << "{";
            { auto conv = [](const unsigned int &v) { return std::to_string(v); };
              oss << "id_of_interpolation_start_game_state_id_for_non_local_character_state=" << conv(obj.id_of_interpolation_start_game_state_id_for_non_local_character_state); }
            oss << ", ";
            { auto conv = [](const unsigned int &v) { return std::to_string(v); };
              oss << "id_of_interpolation_end_game_state_id_for_non_local_character_state=" << conv(obj.id_of_interpolation_end_game_state_id_for_non_local_character_state); }
            oss << ", ";
            { auto conv = [](const double &v) {  std::ostringstream oss;  oss << std::setprecision(std::numeric_limits<double>::max_digits10) << v;  return oss.str();};
              oss << "interpolation_percent_when_fired=" << conv(obj.interpolation_percent_when_fired); }
            oss << "}";
            return oss.str();
        };
            return conversion(*opt);
        };
              oss << "data_to_reconstruct_non_local_character_physics_state_with_entity_interpolation_when_firing_on_server=" << conv(obj.data_to_reconstruct_non_local_character_physics_state_with_entity_interpolation_when_firing_on_server); }
            oss << "}";
            return oss.str();
        };
              oss << "character_firing_update_data=" << conv(obj.character_firing_update_data); }
            oss << "}";
            return oss.str();
        };
              oss << "character_update_data=" << conv(obj.character_update_data); }
            oss << "}";
            return oss.str();
        };
        
            for (size_t i = 0; i < vec.size(); ++i) {
                oss << conversion(vec[i]);
                if (i + 1 < vec.size())
                    oss << ", ";
            }
        
            oss << "}";
            return oss.str();
        };
              oss << "id_tagged_character_update_datas=" << conv(obj.id_tagged_character_update_datas); }
            oss << "}";
            return oss.str();

    }
    CharacterUpdateDataTimeBundle string_to_CharacterUpdateDataTimeBundle(const std::string &s) {
        CharacterUpdateDataTimeBundle obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &input) -> std::vector<IdTaggedCharacterUpdateData> {
            std::string trimmed = input;
            if (!trimmed.empty() && trimmed.front() == '{' && trimmed.back() == '}') {
                trimmed = trimmed.substr(1, trimmed.size() - 2);
            }
        
            std::vector<IdTaggedCharacterUpdateData> result;
            std::regex element_re(R"(.*)");
            auto begin = std::sregex_iterator(trimmed.begin(), trimmed.end(), element_re);
            auto end = std::sregex_iterator();
        
            for (auto it = begin; it != end; ++it) {
                try {
                    auto conversion = [=](const std::string &s) -> IdTaggedCharacterUpdateData {
            IdTaggedCharacterUpdateData obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return static_cast<unsigned int>(std::stoul(s)); };
                    obj.id = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &s) -> CharacterUpdateData {
            CharacterUpdateData obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &s) -> CharacterPhysicsUpdateData {
            CharacterPhysicsUpdateData obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return std::stod(s); };
                    obj.dt = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &s) -> ClientInputState {
            ClientInputState obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return s == "true"; };
                    obj.forward_pressed = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return s == "true"; };
                    obj.back_pressed = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return s == "true"; };
                    obj.right_pressed = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return s == "true"; };
                    obj.left_pressed = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return s == "true"; };
                    obj.jump_pressed = conv(value_str);
                }
            }
            return obj;
        };
                    obj.client_input_state = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) {   std::regex r(R"(\s*\(?\s*([-+]?[0-9]*\.?[0-9]+)\s*,\s*([-+]?[0-9]*\.?[0-9]+)\s*,\s*([-+]?[0-9]*\.?[0-9]+)\s*\)?\s*)");   std::smatch m;   if (std::regex_match(s, m, r)) {     return glm::vec3(std::stof(m[1]), std::stof(m[2]), std::stof(m[3]));   }   throw std::invalid_argument("Invalid glm::vec3 string"); };
                    obj.xy_forward_vector_camera = conv(value_str);
                }
            }
            return obj;
        };
                    obj.character_physics_update_data = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &s) -> CharacterCameraUpdateData {
            CharacterCameraUpdateData obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return std::stod(s); };
                    obj.mouse_position_x = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return std::stod(s); };
                    obj.mouse_position_y = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return std::stod(s); };
                    obj.sensitivity = conv(value_str);
                }
            }
            return obj;
        };
                    obj.character_camera_update_data = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &s) -> CharacterFiringUpdateData {
            CharacterFiringUpdateData obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return s == "true"; };
                    obj.fire_pressed = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &input) -> std::optional<DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer> {
            std::string trimmed = input;
            // Trim whitespace
            trimmed.erase(0, trimmed.find_first_not_of(" \t\n\r"));
            trimmed.erase(trimmed.find_last_not_of(" \t\n\r") + 1);
        
            // Explicit representation of null:
            if (trimmed == "std::nullopt") {
                return std::nullopt;
            }
        
            // Try matching actual value
            std::regex element_re(R"(.*)");
            std::smatch match;
        
            if (std::regex_match(trimmed, match, element_re)) {
                try {
                    auto conversion = [=](const std::string &s) -> DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer {
            DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return static_cast<unsigned int>(std::stoul(s)); };
                    obj.id_of_interpolation_start_game_state_id_for_non_local_character_state = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return static_cast<unsigned int>(std::stoul(s)); };
                    obj.id_of_interpolation_end_game_state_id_for_non_local_character_state = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return std::stod(s); };
                    obj.interpolation_percent_when_fired = conv(value_str);
                }
            }
            return obj;
        };
                    return conversion(trimmed);
                } catch (...) {
                    return std::nullopt;
                }
            }
        
            // Anything else is treated as nullopt
            return std::nullopt;
        };
                    obj.data_to_reconstruct_non_local_character_physics_state_with_entity_interpolation_when_firing_on_server = conv(value_str);
                }
            }
            return obj;
        };
                    obj.character_firing_update_data = conv(value_str);
                }
            }
            return obj;
        };
                    obj.character_update_data = conv(value_str);
                }
            }
            return obj;
        };
                    result.push_back(conversion(it->str()));
                } catch (...) {
                    // Ignore malformed elements
                }
            }
            return result;
        };
                    obj.id_tagged_character_update_datas = conv(value_str);
                }
            }
            return obj;

    }
    std::vector<uint8_t> serialize_CharacterUpdateDataTimeBundle(const CharacterUpdateDataTimeBundle obj) {
        std::vector<uint8_t> buffer;
            { auto ser = [=](const std::vector<IdTaggedCharacterUpdateData>& vec) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            // store vector size first, which is necessary or else we won't know when to stop during deserialization
            size_t count = vec.size();
            buffer.resize(sizeof(size_t));
            std::memcpy(buffer.data(), &count, sizeof(size_t));
        
            auto element_serializer = [=](const IdTaggedCharacterUpdateData& obj) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            { auto ser = [](const unsigned int &v) {   std::vector<uint8_t> buf(sizeof(unsigned int));   std::memcpy(buf.data(), &v, sizeof(unsigned int));   return buf; };
              auto bytes = ser(obj.id);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [=](const CharacterUpdateData& obj) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            { auto ser = [=](const CharacterPhysicsUpdateData& obj) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            { auto ser = [](const double &v) {   std::vector<uint8_t> buf(sizeof(double));   std::memcpy(buf.data(), &v, sizeof(double));   return buf; };
              auto bytes = ser(obj.dt);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [=](const ClientInputState& obj) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            { auto ser = [](const bool &v) {   std::vector<uint8_t> buf(1);   buf[0] = v ? 1 : 0;   return buf; };
              auto bytes = ser(obj.forward_pressed);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const bool &v) {   std::vector<uint8_t> buf(1);   buf[0] = v ? 1 : 0;   return buf; };
              auto bytes = ser(obj.back_pressed);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const bool &v) {   std::vector<uint8_t> buf(1);   buf[0] = v ? 1 : 0;   return buf; };
              auto bytes = ser(obj.right_pressed);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const bool &v) {   std::vector<uint8_t> buf(1);   buf[0] = v ? 1 : 0;   return buf; };
              auto bytes = ser(obj.left_pressed);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const bool &v) {   std::vector<uint8_t> buf(1);   buf[0] = v ? 1 : 0;   return buf; };
              auto bytes = ser(obj.jump_pressed);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;
        };
              auto bytes = ser(obj.client_input_state);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const glm::vec3 &v) {   std::vector<uint8_t> buf(sizeof(glm::vec3));   std::memcpy(buf.data(), &v, sizeof(glm::vec3));   return buf; };
              auto bytes = ser(obj.xy_forward_vector_camera);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;
        };
              auto bytes = ser(obj.character_physics_update_data);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [=](const CharacterCameraUpdateData& obj) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            { auto ser = [](const double &v) {   std::vector<uint8_t> buf(sizeof(double));   std::memcpy(buf.data(), &v, sizeof(double));   return buf; };
              auto bytes = ser(obj.mouse_position_x);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const double &v) {   std::vector<uint8_t> buf(sizeof(double));   std::memcpy(buf.data(), &v, sizeof(double));   return buf; };
              auto bytes = ser(obj.mouse_position_y);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const double &v) {   std::vector<uint8_t> buf(sizeof(double));   std::memcpy(buf.data(), &v, sizeof(double));   return buf; };
              auto bytes = ser(obj.sensitivity);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;
        };
              auto bytes = ser(obj.character_camera_update_data);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [=](const CharacterFiringUpdateData& obj) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            { auto ser = [](const bool &v) {   std::vector<uint8_t> buf(1);   buf[0] = v ? 1 : 0;   return buf; };
              auto bytes = ser(obj.fire_pressed);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [=](const std::optional<DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer>& opt) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
        
            // First byte: 0 = nullopt, 1 = value present
            if (!opt.has_value()) {
                buffer.push_back(0);
                return buffer;
            }
        
            buffer.push_back(1); // value present
            auto element_serializer = [=](const DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer& obj) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            { auto ser = [](const unsigned int &v) {   std::vector<uint8_t> buf(sizeof(unsigned int));   std::memcpy(buf.data(), &v, sizeof(unsigned int));   return buf; };
              auto bytes = ser(obj.id_of_interpolation_start_game_state_id_for_non_local_character_state);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const unsigned int &v) {   std::vector<uint8_t> buf(sizeof(unsigned int));   std::memcpy(buf.data(), &v, sizeof(unsigned int));   return buf; };
              auto bytes = ser(obj.id_of_interpolation_end_game_state_id_for_non_local_character_state);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const double &v) {   std::vector<uint8_t> buf(sizeof(double));   std::memcpy(buf.data(), &v, sizeof(double));   return buf; };
              auto bytes = ser(obj.interpolation_percent_when_fired);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;
        };
            auto elem_bytes = element_serializer(*opt);
            buffer.insert(buffer.end(), elem_bytes.begin(), elem_bytes.end());
        
            return buffer;
        };
              auto bytes = ser(obj.data_to_reconstruct_non_local_character_physics_state_with_entity_interpolation_when_firing_on_server);
              size_t len = bytes.size();
              buffer.resize(buffer.size() + sizeof(size_t));
              std::memcpy(buffer.data() + buffer.size() - sizeof(size_t), &len, sizeof(size_t));
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;
        };
              auto bytes = ser(obj.character_firing_update_data);
              size_t len = bytes.size();
              buffer.resize(buffer.size() + sizeof(size_t));
              std::memcpy(buffer.data() + buffer.size() - sizeof(size_t), &len, sizeof(size_t));
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;
        };
              auto bytes = ser(obj.character_update_data);
              size_t len = bytes.size();
              buffer.resize(buffer.size() + sizeof(size_t));
              std::memcpy(buffer.data() + buffer.size() - sizeof(size_t), &len, sizeof(size_t));
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;
        };
            for (const auto& elem : vec) {
                auto elem_bytes = element_serializer(elem);
                size_t elem_size = elem_bytes.size();
                // increase the active buffers size so we can fit the next object in
                buffer.resize(buffer.size() + sizeof(size_t));
                // copy in the size of the object we're about to insert before that object
                std::memcpy(buffer.data() + buffer.size() - sizeof(size_t), &elem_size, sizeof(size_t));
                // dump the object in
                buffer.insert(buffer.end(), elem_bytes.begin(), elem_bytes.end());
            }
            return buffer;
        };
              auto bytes = ser(obj.id_tagged_character_update_datas);
              size_t len = bytes.size();
              buffer.resize(buffer.size() + sizeof(size_t));
              std::memcpy(buffer.data() + buffer.size() - sizeof(size_t), &len, sizeof(size_t));
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;

    }
    size_t size_when_serialized_CharacterUpdateDataTimeBundle(const CharacterUpdateDataTimeBundle obj) {
        size_t total = 0;
            { auto size_fn = [=](const std::vector<IdTaggedCharacterUpdateData>& vec) -> size_t {
            size_t total_size = sizeof(size_t); // space for storing count
            auto element_size_func = [=](const IdTaggedCharacterUpdateData& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              total += size_fn(obj.id); }
            { auto size_fn = [=](const CharacterUpdateData& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [=](const CharacterPhysicsUpdateData& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.dt); }
            { auto size_fn = [=](const ClientInputState& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.forward_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.back_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.right_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.left_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.jump_pressed); }
            return total;
        };
              total += size_fn(obj.client_input_state); }
            { auto size_fn = [](const glm::vec3 &v) { return sizeof(glm::vec3); };
              total += size_fn(obj.xy_forward_vector_camera); }
            return total;
        };
              total += size_fn(obj.character_physics_update_data); }
            { auto size_fn = [=](const CharacterCameraUpdateData& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.mouse_position_x); }
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.mouse_position_y); }
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.sensitivity); }
            return total;
        };
              total += size_fn(obj.character_camera_update_data); }
            { auto size_fn = [=](const CharacterFiringUpdateData& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.fire_pressed); }
            { auto size_fn = [=](const std::optional<DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer>& opt) -> size_t {
            size_t total_size = 1; // presence flag (1 byte)
        
            if (!opt.has_value()) {
                return total_size; // only the presence flag
            }
        
            // Value is present, delegate to inner type's size function
            auto element_size_func = [=](const DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              total += size_fn(obj.id_of_interpolation_start_game_state_id_for_non_local_character_state); }
            { auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              total += size_fn(obj.id_of_interpolation_end_game_state_id_for_non_local_character_state); }
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.interpolation_percent_when_fired); }
            return total;
        };
            total_size += element_size_func(*opt);
        
            return total_size;
        };
              total += sizeof(size_t); // length prefix
              total += size_fn(obj.data_to_reconstruct_non_local_character_physics_state_with_entity_interpolation_when_firing_on_server); }
            return total;
        };
              total += sizeof(size_t); // length prefix
              total += size_fn(obj.character_firing_update_data); }
            return total;
        };
              total += sizeof(size_t); // length prefix
              total += size_fn(obj.character_update_data); }
            return total;
        };
            for (const auto& elem : vec) {
                size_t elem_size = element_size_func(elem);
                total_size += sizeof(size_t) + elem_size; // size prefix + data
            }
            return total_size;
        };
              total += sizeof(size_t); // length prefix
              total += size_fn(obj.id_tagged_character_update_datas); }
            return total;

    }
    CharacterUpdateDataTimeBundle deserialize_CharacterUpdateDataTimeBundle(const std::vector<uint8_t> &buffer) {
        CharacterUpdateDataTimeBundle obj;
            size_t offset = 0;
            { auto deser = [=](const std::vector<uint8_t>& buffer) -> std::vector<IdTaggedCharacterUpdateData> {
            std::vector<IdTaggedCharacterUpdateData> result;
            if (buffer.size() < sizeof(size_t)) return result;
            size_t count;
            std::memcpy(&count, buffer.data(), sizeof(size_t));
        
            size_t offset = sizeof(size_t);
            auto element_deserializer = [=](const std::vector<uint8_t> &buffer) -> IdTaggedCharacterUpdateData {
            IdTaggedCharacterUpdateData obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   unsigned int v;   std::memcpy(&v, buf.data(), sizeof(unsigned int));   return v; };
              auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              size_t len = size_fn(obj.id);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.id = deser(slice);
              offset += len;
            }
            { auto deser = [=](const std::vector<uint8_t> &buffer) -> CharacterUpdateData {
            CharacterUpdateData obj;
            size_t offset = 0;
            { auto deser = [=](const std::vector<uint8_t> &buffer) -> CharacterPhysicsUpdateData {
            CharacterPhysicsUpdateData obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   double v;   std::memcpy(&v, buf.data(), sizeof(double));   return v; };
              auto size_fn = [](const double &v) { return sizeof(double); };
              size_t len = size_fn(obj.dt);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.dt = deser(slice);
              offset += len;
            }
            { auto deser = [=](const std::vector<uint8_t> &buffer) -> ClientInputState {
            ClientInputState obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   return buf[0] != 0; };
              auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              size_t len = size_fn(obj.forward_pressed);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.forward_pressed = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   return buf[0] != 0; };
              auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              size_t len = size_fn(obj.back_pressed);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.back_pressed = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   return buf[0] != 0; };
              auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              size_t len = size_fn(obj.right_pressed);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.right_pressed = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   return buf[0] != 0; };
              auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              size_t len = size_fn(obj.left_pressed);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.left_pressed = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   return buf[0] != 0; };
              auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              size_t len = size_fn(obj.jump_pressed);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.jump_pressed = deser(slice);
              offset += len;
            }
            return obj;
        };
              auto size_fn = [=](const ClientInputState& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.forward_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.back_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.right_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.left_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.jump_pressed); }
            return total;
        };
              size_t len = size_fn(obj.client_input_state);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.client_input_state = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   glm::vec3 v;   std::memcpy(&v, buf.data(), sizeof(glm::vec3));   return v; };
              auto size_fn = [](const glm::vec3 &v) { return sizeof(glm::vec3); };
              size_t len = size_fn(obj.xy_forward_vector_camera);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.xy_forward_vector_camera = deser(slice);
              offset += len;
            }
            return obj;
        };
              auto size_fn = [=](const CharacterPhysicsUpdateData& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.dt); }
            { auto size_fn = [=](const ClientInputState& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.forward_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.back_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.right_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.left_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.jump_pressed); }
            return total;
        };
              total += size_fn(obj.client_input_state); }
            { auto size_fn = [](const glm::vec3 &v) { return sizeof(glm::vec3); };
              total += size_fn(obj.xy_forward_vector_camera); }
            return total;
        };
              size_t len = size_fn(obj.character_physics_update_data);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.character_physics_update_data = deser(slice);
              offset += len;
            }
            { auto deser = [=](const std::vector<uint8_t> &buffer) -> CharacterCameraUpdateData {
            CharacterCameraUpdateData obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   double v;   std::memcpy(&v, buf.data(), sizeof(double));   return v; };
              auto size_fn = [](const double &v) { return sizeof(double); };
              size_t len = size_fn(obj.mouse_position_x);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.mouse_position_x = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   double v;   std::memcpy(&v, buf.data(), sizeof(double));   return v; };
              auto size_fn = [](const double &v) { return sizeof(double); };
              size_t len = size_fn(obj.mouse_position_y);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.mouse_position_y = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   double v;   std::memcpy(&v, buf.data(), sizeof(double));   return v; };
              auto size_fn = [](const double &v) { return sizeof(double); };
              size_t len = size_fn(obj.sensitivity);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.sensitivity = deser(slice);
              offset += len;
            }
            return obj;
        };
              auto size_fn = [=](const CharacterCameraUpdateData& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.mouse_position_x); }
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.mouse_position_y); }
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.sensitivity); }
            return total;
        };
              size_t len = size_fn(obj.character_camera_update_data);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.character_camera_update_data = deser(slice);
              offset += len;
            }
            { auto deser = [=](const std::vector<uint8_t> &buffer) -> CharacterFiringUpdateData {
            CharacterFiringUpdateData obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   return buf[0] != 0; };
              auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              size_t len = size_fn(obj.fire_pressed);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.fire_pressed = deser(slice);
              offset += len;
            }
            { auto deser = [=](const std::vector<uint8_t>& buffer) -> std::optional<DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer> {
            if (buffer.empty()) return std::nullopt;  // empty buffer
        
            // First byte indicates presence of value
            uint8_t has_value = buffer[0];
            if (has_value == 0) return std::nullopt;
        
            // Value is present, delegate deserialization to inner type
            auto element_deserializer = [=](const std::vector<uint8_t> &buffer) -> DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer {
            DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   unsigned int v;   std::memcpy(&v, buf.data(), sizeof(unsigned int));   return v; };
              auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              size_t len = size_fn(obj.id_of_interpolation_start_game_state_id_for_non_local_character_state);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.id_of_interpolation_start_game_state_id_for_non_local_character_state = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   unsigned int v;   std::memcpy(&v, buf.data(), sizeof(unsigned int));   return v; };
              auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              size_t len = size_fn(obj.id_of_interpolation_end_game_state_id_for_non_local_character_state);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.id_of_interpolation_end_game_state_id_for_non_local_character_state = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   double v;   std::memcpy(&v, buf.data(), sizeof(double));   return v; };
              auto size_fn = [](const double &v) { return sizeof(double); };
              size_t len = size_fn(obj.interpolation_percent_when_fired);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.interpolation_percent_when_fired = deser(slice);
              offset += len;
            }
            return obj;
        };
            std::vector<uint8_t> elem_bytes(buffer.begin() + 1, buffer.end());
            return element_deserializer(elem_bytes);
        };
              if (offset + sizeof(size_t) > buffer.size()) return obj;
              size_t len = 0;
              std::memcpy(&len, buffer.data() + offset, sizeof(size_t));
              offset += sizeof(size_t);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.data_to_reconstruct_non_local_character_physics_state_with_entity_interpolation_when_firing_on_server = deser(slice);
              offset += len;
            }
            return obj;
        };
              if (offset + sizeof(size_t) > buffer.size()) return obj;
              size_t len = 0;
              std::memcpy(&len, buffer.data() + offset, sizeof(size_t));
              offset += sizeof(size_t);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.character_firing_update_data = deser(slice);
              offset += len;
            }
            return obj;
        };
              if (offset + sizeof(size_t) > buffer.size()) return obj;
              size_t len = 0;
              std::memcpy(&len, buffer.data() + offset, sizeof(size_t));
              offset += sizeof(size_t);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.character_update_data = deser(slice);
              offset += len;
            }
            return obj;
        };
            for (size_t i = 0; i < count; ++i) {
                // element is variably sized: read elem_size first
                if (offset + sizeof(size_t) > buffer.size()) break;
                size_t elem_size;
                std::memcpy(&elem_size, buffer.data() + offset, sizeof(size_t));
                offset += sizeof(size_t);
                if (offset + elem_size > buffer.size()) break;
                std::vector<uint8_t> elem_buf(buffer.begin() + offset, buffer.begin() + offset + elem_size);
                IdTaggedCharacterUpdateData elem = element_deserializer(elem_buf);
                result.push_back(elem);
                offset += elem_size;
            }
            return result;
        };
              if (offset + sizeof(size_t) > buffer.size()) return obj;
              size_t len = 0;
              std::memcpy(&len, buffer.data() + offset, sizeof(size_t));
              offset += sizeof(size_t);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.id_tagged_character_update_datas = deser(slice);
              offset += len;
            }
            return obj;

    }
    std::string SuccessfullyConnected_to_string(const SuccessfullyConnected obj) {
        std::ostringstream oss;
            oss << "{";
            { auto conv = [](const unsigned int &v) { return std::to_string(v); };
              oss << "client_id=" << conv(obj.client_id); }
            oss << "}";
            return oss.str();

    }
    SuccessfullyConnected string_to_SuccessfullyConnected(const std::string &s) {
        SuccessfullyConnected obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return static_cast<unsigned int>(std::stoul(s)); };
                    obj.client_id = conv(value_str);
                }
            }
            return obj;

    }
    std::vector<uint8_t> serialize_SuccessfullyConnected(const SuccessfullyConnected obj) {
        std::vector<uint8_t> buffer;
            { auto ser = [](const unsigned int &v) {   std::vector<uint8_t> buf(sizeof(unsigned int));   std::memcpy(buf.data(), &v, sizeof(unsigned int));   return buf; };
              auto bytes = ser(obj.client_id);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;

    }
    size_t size_when_serialized_SuccessfullyConnected(const SuccessfullyConnected obj) {
        size_t total = 0;
            { auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              total += size_fn(obj.client_id); }
            return total;

    }
    SuccessfullyConnected deserialize_SuccessfullyConnected(const std::vector<uint8_t> &buffer) {
        SuccessfullyConnected obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   unsigned int v;   std::memcpy(&v, buf.data(), sizeof(unsigned int));   return v; };
              auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              size_t len = size_fn(obj.client_id);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.client_id = deser(slice);
              offset += len;
            }
            return obj;

    }
    std::string SuccessfullyConnectedPacket_to_string(const SuccessfullyConnectedPacket obj) {
        std::ostringstream oss;
            oss << "{";
            { auto conv = [=](const PacketHeader& obj) -> std::string {
            std::ostringstream oss;
            oss << "{";
            { auto conv = [=](PacketType value) -> std::string {
            switch(value) {
                case PacketType::CLIENT_UPDATE_DATA: return "PacketType::CLIENT_UPDATE_DATA";
                case PacketType::GAME_STATE: return "PacketType::GAME_STATE";
                case PacketType::NUM_ENUMERATORS: return "PacketType::NUM_ENUMERATORS";
                default: return "<unknown PacketType>";
            }
        };
              oss << "type=" << conv(obj.type); }
            oss << ", ";
            { auto conv = [](const uint32_t &v) { return std::to_string(v); };
              oss << "size_of_data_without_header=" << conv(obj.size_of_data_without_header); }
            oss << "}";
            return oss.str();
        };
              oss << "packet_header=" << conv(obj.packet_header); }
            oss << ", ";
            { auto conv = [=](const SuccessfullyConnected& obj) -> std::string {
            std::ostringstream oss;
            oss << "{";
            { auto conv = [](const unsigned int &v) { return std::to_string(v); };
              oss << "client_id=" << conv(obj.client_id); }
            oss << "}";
            return oss.str();
        };
              oss << "successfully_connected=" << conv(obj.successfully_connected); }
            oss << "}";
            return oss.str();

    }
    SuccessfullyConnectedPacket string_to_SuccessfullyConnectedPacket(const std::string &s) {
        SuccessfullyConnectedPacket obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &s) -> PacketHeader {
            PacketHeader obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &s) -> PacketType {
            if (s == "PacketType::CLIENT_UPDATE_DATA") return PacketType::CLIENT_UPDATE_DATA;
            if (s == "PacketType::GAME_STATE") return PacketType::GAME_STATE;
            if (s == "PacketType::NUM_ENUMERATORS") return PacketType::NUM_ENUMERATORS;
            return static_cast<PacketType>(0); // default fallback
        };
                    obj.type = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return static_cast<uint32_t>(std::stoul(s)); };
                    obj.size_of_data_without_header = conv(value_str);
                }
            }
            return obj;
        };
                    obj.packet_header = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &s) -> SuccessfullyConnected {
            SuccessfullyConnected obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return static_cast<unsigned int>(std::stoul(s)); };
                    obj.client_id = conv(value_str);
                }
            }
            return obj;
        };
                    obj.successfully_connected = conv(value_str);
                }
            }
            return obj;

    }
    std::vector<uint8_t> serialize_SuccessfullyConnectedPacket(const SuccessfullyConnectedPacket obj) {
        std::vector<uint8_t> buffer;
            { auto ser = [=](const PacketHeader& obj) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            { auto ser = [=](PacketType value) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer(sizeof(uint8_t));
            uint8_t raw = static_cast<uint8_t>(value);
            std::memcpy(buffer.data(), &raw, sizeof(uint8_t));
            return buffer;
        };
              auto bytes = ser(obj.type);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const uint32_t &v) {   std::vector<uint8_t> buf(sizeof(uint32_t));   std::memcpy(buf.data(), &v, sizeof(uint32_t));   return buf; };
              auto bytes = ser(obj.size_of_data_without_header);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;
        };
              auto bytes = ser(obj.packet_header);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [=](const SuccessfullyConnected& obj) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            { auto ser = [](const unsigned int &v) {   std::vector<uint8_t> buf(sizeof(unsigned int));   std::memcpy(buf.data(), &v, sizeof(unsigned int));   return buf; };
              auto bytes = ser(obj.client_id);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;
        };
              auto bytes = ser(obj.successfully_connected);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;

    }
    size_t size_when_serialized_SuccessfullyConnectedPacket(const SuccessfullyConnectedPacket obj) {
        size_t total = 0;
            { auto size_fn = [=](const PacketHeader& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [=](const PacketType &obj) -> size_t {
            return sizeof(uint8_t);
        };
              total += size_fn(obj.type); }
            { auto size_fn = [](const uint32_t &v) { return sizeof(uint32_t); };
              total += size_fn(obj.size_of_data_without_header); }
            return total;
        };
              total += size_fn(obj.packet_header); }
            { auto size_fn = [=](const SuccessfullyConnected& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              total += size_fn(obj.client_id); }
            return total;
        };
              total += size_fn(obj.successfully_connected); }
            return total;

    }
    SuccessfullyConnectedPacket deserialize_SuccessfullyConnectedPacket(const std::vector<uint8_t> &buffer) {
        SuccessfullyConnectedPacket obj;
            size_t offset = 0;
            { auto deser = [=](const std::vector<uint8_t> &buffer) -> PacketHeader {
            PacketHeader obj;
            size_t offset = 0;
            { auto deser = [=](const std::vector<uint8_t> &buffer) -> PacketType {
            if (buffer.size() < sizeof(uint8_t)) return static_cast<PacketType>(0);
            uint8_t raw = 0;
            std::memcpy(&raw, buffer.data(), sizeof(uint8_t));
            return static_cast<PacketType>(raw);
        };
              auto size_fn = [=](const PacketType &obj) -> size_t {
            return sizeof(uint8_t);
        };
              size_t len = size_fn(obj.type);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.type = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   uint32_t v;   std::memcpy(&v, buf.data(), sizeof(uint32_t));   return v; };
              auto size_fn = [](const uint32_t &v) { return sizeof(uint32_t); };
              size_t len = size_fn(obj.size_of_data_without_header);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.size_of_data_without_header = deser(slice);
              offset += len;
            }
            return obj;
        };
              auto size_fn = [=](const PacketHeader& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [=](const PacketType &obj) -> size_t {
            return sizeof(uint8_t);
        };
              total += size_fn(obj.type); }
            { auto size_fn = [](const uint32_t &v) { return sizeof(uint32_t); };
              total += size_fn(obj.size_of_data_without_header); }
            return total;
        };
              size_t len = size_fn(obj.packet_header);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.packet_header = deser(slice);
              offset += len;
            }
            { auto deser = [=](const std::vector<uint8_t> &buffer) -> SuccessfullyConnected {
            SuccessfullyConnected obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   unsigned int v;   std::memcpy(&v, buf.data(), sizeof(unsigned int));   return v; };
              auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              size_t len = size_fn(obj.client_id);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.client_id = deser(slice);
              offset += len;
            }
            return obj;
        };
              auto size_fn = [=](const SuccessfullyConnected& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              total += size_fn(obj.client_id); }
            return total;
        };
              size_t len = size_fn(obj.successfully_connected);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.successfully_connected = deser(slice);
              offset += len;
            }
            return obj;

    }
    std::string ClientUpdateData_to_string(const ClientUpdateData obj) {
        std::ostringstream oss;
            oss << "{";
            { auto conv = [](const unsigned int &v) { return std::to_string(v); };
              oss << "id=" << conv(obj.id); }
            oss << ", ";
            { auto conv = [=](const std::vector<CharacterUpdateDataTimeBundle>& vec) -> std::string {
            std::ostringstream oss;
            oss << "{";
            auto conversion = [=](const CharacterUpdateDataTimeBundle& obj) -> std::string {
            std::ostringstream oss;
            oss << "{";
            { auto conv = [=](const std::vector<IdTaggedCharacterUpdateData>& vec) -> std::string {
            std::ostringstream oss;
            oss << "{";
            auto conversion = [=](const IdTaggedCharacterUpdateData& obj) -> std::string {
            std::ostringstream oss;
            oss << "{";
            { auto conv = [](const unsigned int &v) { return std::to_string(v); };
              oss << "id=" << conv(obj.id); }
            oss << ", ";
            { auto conv = [=](const CharacterUpdateData& obj) -> std::string {
            std::ostringstream oss;
            oss << "{";
            { auto conv = [=](const CharacterPhysicsUpdateData& obj) -> std::string {
            std::ostringstream oss;
            oss << "{";
            { auto conv = [](const double &v) {  std::ostringstream oss;  oss << std::setprecision(std::numeric_limits<double>::max_digits10) << v;  return oss.str();};
              oss << "dt=" << conv(obj.dt); }
            oss << ", ";
            { auto conv = [=](const ClientInputState& obj) -> std::string {
            std::ostringstream oss;
            oss << "{";
            { auto conv = [](const bool &v) { return v ? "true" : "false"; };
              oss << "forward_pressed=" << conv(obj.forward_pressed); }
            oss << ", ";
            { auto conv = [](const bool &v) { return v ? "true" : "false"; };
              oss << "back_pressed=" << conv(obj.back_pressed); }
            oss << ", ";
            { auto conv = [](const bool &v) { return v ? "true" : "false"; };
              oss << "right_pressed=" << conv(obj.right_pressed); }
            oss << ", ";
            { auto conv = [](const bool &v) { return v ? "true" : "false"; };
              oss << "left_pressed=" << conv(obj.left_pressed); }
            oss << ", ";
            { auto conv = [](const bool &v) { return v ? "true" : "false"; };
              oss << "jump_pressed=" << conv(obj.jump_pressed); }
            oss << "}";
            return oss.str();
        };
              oss << "client_input_state=" << conv(obj.client_input_state); }
            oss << ", ";
            { auto conv = [](const glm::vec3 &v) {  int precision =  std::numeric_limits<float>::max_digits10; std::ostringstream oss; oss << std::fixed << std::setprecision(precision); oss << '(' << v.x << ',' << ' ' << v.y << ',' << ' ' << v.z <<  ')'; return oss.str();};
              oss << "xy_forward_vector_camera=" << conv(obj.xy_forward_vector_camera); }
            oss << "}";
            return oss.str();
        };
              oss << "character_physics_update_data=" << conv(obj.character_physics_update_data); }
            oss << ", ";
            { auto conv = [=](const CharacterCameraUpdateData& obj) -> std::string {
            std::ostringstream oss;
            oss << "{";
            { auto conv = [](const double &v) {  std::ostringstream oss;  oss << std::setprecision(std::numeric_limits<double>::max_digits10) << v;  return oss.str();};
              oss << "mouse_position_x=" << conv(obj.mouse_position_x); }
            oss << ", ";
            { auto conv = [](const double &v) {  std::ostringstream oss;  oss << std::setprecision(std::numeric_limits<double>::max_digits10) << v;  return oss.str();};
              oss << "mouse_position_y=" << conv(obj.mouse_position_y); }
            oss << ", ";
            { auto conv = [](const double &v) {  std::ostringstream oss;  oss << std::setprecision(std::numeric_limits<double>::max_digits10) << v;  return oss.str();};
              oss << "sensitivity=" << conv(obj.sensitivity); }
            oss << "}";
            return oss.str();
        };
              oss << "character_camera_update_data=" << conv(obj.character_camera_update_data); }
            oss << ", ";
            { auto conv = [=](const CharacterFiringUpdateData& obj) -> std::string {
            std::ostringstream oss;
            oss << "{";
            { auto conv = [](const bool &v) { return v ? "true" : "false"; };
              oss << "fire_pressed=" << conv(obj.fire_pressed); }
            oss << ", ";
            { auto conv = [=](const std::optional<DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer>& opt) -> std::string {
            if (!opt.has_value()) {
                return "std::nullopt";
            }
        
            auto conversion = [=](const DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer& obj) -> std::string {
            std::ostringstream oss;
            oss << "{";
            { auto conv = [](const unsigned int &v) { return std::to_string(v); };
              oss << "id_of_interpolation_start_game_state_id_for_non_local_character_state=" << conv(obj.id_of_interpolation_start_game_state_id_for_non_local_character_state); }
            oss << ", ";
            { auto conv = [](const unsigned int &v) { return std::to_string(v); };
              oss << "id_of_interpolation_end_game_state_id_for_non_local_character_state=" << conv(obj.id_of_interpolation_end_game_state_id_for_non_local_character_state); }
            oss << ", ";
            { auto conv = [](const double &v) {  std::ostringstream oss;  oss << std::setprecision(std::numeric_limits<double>::max_digits10) << v;  return oss.str();};
              oss << "interpolation_percent_when_fired=" << conv(obj.interpolation_percent_when_fired); }
            oss << "}";
            return oss.str();
        };
            return conversion(*opt);
        };
              oss << "data_to_reconstruct_non_local_character_physics_state_with_entity_interpolation_when_firing_on_server=" << conv(obj.data_to_reconstruct_non_local_character_physics_state_with_entity_interpolation_when_firing_on_server); }
            oss << "}";
            return oss.str();
        };
              oss << "character_firing_update_data=" << conv(obj.character_firing_update_data); }
            oss << "}";
            return oss.str();
        };
              oss << "character_update_data=" << conv(obj.character_update_data); }
            oss << "}";
            return oss.str();
        };
        
            for (size_t i = 0; i < vec.size(); ++i) {
                oss << conversion(vec[i]);
                if (i + 1 < vec.size())
                    oss << ", ";
            }
        
            oss << "}";
            return oss.str();
        };
              oss << "id_tagged_character_update_datas=" << conv(obj.id_tagged_character_update_datas); }
            oss << "}";
            return oss.str();
        };
        
            for (size_t i = 0; i < vec.size(); ++i) {
                oss << conversion(vec[i]);
                if (i + 1 < vec.size())
                    oss << ", ";
            }
        
            oss << "}";
            return oss.str();
        };
              oss << "character_update_data_time_bundles=" << conv(obj.character_update_data_time_bundles); }
            oss << "}";
            return oss.str();

    }
    ClientUpdateData string_to_ClientUpdateData(const std::string &s) {
        ClientUpdateData obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return static_cast<unsigned int>(std::stoul(s)); };
                    obj.id = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &input) -> std::vector<CharacterUpdateDataTimeBundle> {
            std::string trimmed = input;
            if (!trimmed.empty() && trimmed.front() == '{' && trimmed.back() == '}') {
                trimmed = trimmed.substr(1, trimmed.size() - 2);
            }
        
            std::vector<CharacterUpdateDataTimeBundle> result;
            std::regex element_re(R"(.*)");
            auto begin = std::sregex_iterator(trimmed.begin(), trimmed.end(), element_re);
            auto end = std::sregex_iterator();
        
            for (auto it = begin; it != end; ++it) {
                try {
                    auto conversion = [=](const std::string &s) -> CharacterUpdateDataTimeBundle {
            CharacterUpdateDataTimeBundle obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &input) -> std::vector<IdTaggedCharacterUpdateData> {
            std::string trimmed = input;
            if (!trimmed.empty() && trimmed.front() == '{' && trimmed.back() == '}') {
                trimmed = trimmed.substr(1, trimmed.size() - 2);
            }
        
            std::vector<IdTaggedCharacterUpdateData> result;
            std::regex element_re(R"(.*)");
            auto begin = std::sregex_iterator(trimmed.begin(), trimmed.end(), element_re);
            auto end = std::sregex_iterator();
        
            for (auto it = begin; it != end; ++it) {
                try {
                    auto conversion = [=](const std::string &s) -> IdTaggedCharacterUpdateData {
            IdTaggedCharacterUpdateData obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return static_cast<unsigned int>(std::stoul(s)); };
                    obj.id = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &s) -> CharacterUpdateData {
            CharacterUpdateData obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &s) -> CharacterPhysicsUpdateData {
            CharacterPhysicsUpdateData obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return std::stod(s); };
                    obj.dt = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &s) -> ClientInputState {
            ClientInputState obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return s == "true"; };
                    obj.forward_pressed = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return s == "true"; };
                    obj.back_pressed = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return s == "true"; };
                    obj.right_pressed = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return s == "true"; };
                    obj.left_pressed = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return s == "true"; };
                    obj.jump_pressed = conv(value_str);
                }
            }
            return obj;
        };
                    obj.client_input_state = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) {   std::regex r(R"(\s*\(?\s*([-+]?[0-9]*\.?[0-9]+)\s*,\s*([-+]?[0-9]*\.?[0-9]+)\s*,\s*([-+]?[0-9]*\.?[0-9]+)\s*\)?\s*)");   std::smatch m;   if (std::regex_match(s, m, r)) {     return glm::vec3(std::stof(m[1]), std::stof(m[2]), std::stof(m[3]));   }   throw std::invalid_argument("Invalid glm::vec3 string"); };
                    obj.xy_forward_vector_camera = conv(value_str);
                }
            }
            return obj;
        };
                    obj.character_physics_update_data = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &s) -> CharacterCameraUpdateData {
            CharacterCameraUpdateData obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return std::stod(s); };
                    obj.mouse_position_x = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return std::stod(s); };
                    obj.mouse_position_y = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return std::stod(s); };
                    obj.sensitivity = conv(value_str);
                }
            }
            return obj;
        };
                    obj.character_camera_update_data = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &s) -> CharacterFiringUpdateData {
            CharacterFiringUpdateData obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return s == "true"; };
                    obj.fire_pressed = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &input) -> std::optional<DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer> {
            std::string trimmed = input;
            // Trim whitespace
            trimmed.erase(0, trimmed.find_first_not_of(" \t\n\r"));
            trimmed.erase(trimmed.find_last_not_of(" \t\n\r") + 1);
        
            // Explicit representation of null:
            if (trimmed == "std::nullopt") {
                return std::nullopt;
            }
        
            // Try matching actual value
            std::regex element_re(R"(.*)");
            std::smatch match;
        
            if (std::regex_match(trimmed, match, element_re)) {
                try {
                    auto conversion = [=](const std::string &s) -> DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer {
            DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return static_cast<unsigned int>(std::stoul(s)); };
                    obj.id_of_interpolation_start_game_state_id_for_non_local_character_state = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return static_cast<unsigned int>(std::stoul(s)); };
                    obj.id_of_interpolation_end_game_state_id_for_non_local_character_state = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return std::stod(s); };
                    obj.interpolation_percent_when_fired = conv(value_str);
                }
            }
            return obj;
        };
                    return conversion(trimmed);
                } catch (...) {
                    return std::nullopt;
                }
            }
        
            // Anything else is treated as nullopt
            return std::nullopt;
        };
                    obj.data_to_reconstruct_non_local_character_physics_state_with_entity_interpolation_when_firing_on_server = conv(value_str);
                }
            }
            return obj;
        };
                    obj.character_firing_update_data = conv(value_str);
                }
            }
            return obj;
        };
                    obj.character_update_data = conv(value_str);
                }
            }
            return obj;
        };
                    result.push_back(conversion(it->str()));
                } catch (...) {
                    // Ignore malformed elements
                }
            }
            return result;
        };
                    obj.id_tagged_character_update_datas = conv(value_str);
                }
            }
            return obj;
        };
                    result.push_back(conversion(it->str()));
                } catch (...) {
                    // Ignore malformed elements
                }
            }
            return result;
        };
                    obj.character_update_data_time_bundles = conv(value_str);
                }
            }
            return obj;

    }
    std::vector<uint8_t> serialize_ClientUpdateData(const ClientUpdateData obj) {
        std::vector<uint8_t> buffer;
            { auto ser = [](const unsigned int &v) {   std::vector<uint8_t> buf(sizeof(unsigned int));   std::memcpy(buf.data(), &v, sizeof(unsigned int));   return buf; };
              auto bytes = ser(obj.id);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [=](const std::vector<CharacterUpdateDataTimeBundle>& vec) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            // store vector size first, which is necessary or else we won't know when to stop during deserialization
            size_t count = vec.size();
            buffer.resize(sizeof(size_t));
            std::memcpy(buffer.data(), &count, sizeof(size_t));
        
            auto element_serializer = [=](const CharacterUpdateDataTimeBundle& obj) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            { auto ser = [=](const std::vector<IdTaggedCharacterUpdateData>& vec) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            // store vector size first, which is necessary or else we won't know when to stop during deserialization
            size_t count = vec.size();
            buffer.resize(sizeof(size_t));
            std::memcpy(buffer.data(), &count, sizeof(size_t));
        
            auto element_serializer = [=](const IdTaggedCharacterUpdateData& obj) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            { auto ser = [](const unsigned int &v) {   std::vector<uint8_t> buf(sizeof(unsigned int));   std::memcpy(buf.data(), &v, sizeof(unsigned int));   return buf; };
              auto bytes = ser(obj.id);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [=](const CharacterUpdateData& obj) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            { auto ser = [=](const CharacterPhysicsUpdateData& obj) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            { auto ser = [](const double &v) {   std::vector<uint8_t> buf(sizeof(double));   std::memcpy(buf.data(), &v, sizeof(double));   return buf; };
              auto bytes = ser(obj.dt);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [=](const ClientInputState& obj) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            { auto ser = [](const bool &v) {   std::vector<uint8_t> buf(1);   buf[0] = v ? 1 : 0;   return buf; };
              auto bytes = ser(obj.forward_pressed);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const bool &v) {   std::vector<uint8_t> buf(1);   buf[0] = v ? 1 : 0;   return buf; };
              auto bytes = ser(obj.back_pressed);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const bool &v) {   std::vector<uint8_t> buf(1);   buf[0] = v ? 1 : 0;   return buf; };
              auto bytes = ser(obj.right_pressed);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const bool &v) {   std::vector<uint8_t> buf(1);   buf[0] = v ? 1 : 0;   return buf; };
              auto bytes = ser(obj.left_pressed);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const bool &v) {   std::vector<uint8_t> buf(1);   buf[0] = v ? 1 : 0;   return buf; };
              auto bytes = ser(obj.jump_pressed);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;
        };
              auto bytes = ser(obj.client_input_state);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const glm::vec3 &v) {   std::vector<uint8_t> buf(sizeof(glm::vec3));   std::memcpy(buf.data(), &v, sizeof(glm::vec3));   return buf; };
              auto bytes = ser(obj.xy_forward_vector_camera);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;
        };
              auto bytes = ser(obj.character_physics_update_data);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [=](const CharacterCameraUpdateData& obj) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            { auto ser = [](const double &v) {   std::vector<uint8_t> buf(sizeof(double));   std::memcpy(buf.data(), &v, sizeof(double));   return buf; };
              auto bytes = ser(obj.mouse_position_x);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const double &v) {   std::vector<uint8_t> buf(sizeof(double));   std::memcpy(buf.data(), &v, sizeof(double));   return buf; };
              auto bytes = ser(obj.mouse_position_y);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const double &v) {   std::vector<uint8_t> buf(sizeof(double));   std::memcpy(buf.data(), &v, sizeof(double));   return buf; };
              auto bytes = ser(obj.sensitivity);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;
        };
              auto bytes = ser(obj.character_camera_update_data);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [=](const CharacterFiringUpdateData& obj) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            { auto ser = [](const bool &v) {   std::vector<uint8_t> buf(1);   buf[0] = v ? 1 : 0;   return buf; };
              auto bytes = ser(obj.fire_pressed);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [=](const std::optional<DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer>& opt) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
        
            // First byte: 0 = nullopt, 1 = value present
            if (!opt.has_value()) {
                buffer.push_back(0);
                return buffer;
            }
        
            buffer.push_back(1); // value present
            auto element_serializer = [=](const DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer& obj) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            { auto ser = [](const unsigned int &v) {   std::vector<uint8_t> buf(sizeof(unsigned int));   std::memcpy(buf.data(), &v, sizeof(unsigned int));   return buf; };
              auto bytes = ser(obj.id_of_interpolation_start_game_state_id_for_non_local_character_state);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const unsigned int &v) {   std::vector<uint8_t> buf(sizeof(unsigned int));   std::memcpy(buf.data(), &v, sizeof(unsigned int));   return buf; };
              auto bytes = ser(obj.id_of_interpolation_end_game_state_id_for_non_local_character_state);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const double &v) {   std::vector<uint8_t> buf(sizeof(double));   std::memcpy(buf.data(), &v, sizeof(double));   return buf; };
              auto bytes = ser(obj.interpolation_percent_when_fired);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;
        };
            auto elem_bytes = element_serializer(*opt);
            buffer.insert(buffer.end(), elem_bytes.begin(), elem_bytes.end());
        
            return buffer;
        };
              auto bytes = ser(obj.data_to_reconstruct_non_local_character_physics_state_with_entity_interpolation_when_firing_on_server);
              size_t len = bytes.size();
              buffer.resize(buffer.size() + sizeof(size_t));
              std::memcpy(buffer.data() + buffer.size() - sizeof(size_t), &len, sizeof(size_t));
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;
        };
              auto bytes = ser(obj.character_firing_update_data);
              size_t len = bytes.size();
              buffer.resize(buffer.size() + sizeof(size_t));
              std::memcpy(buffer.data() + buffer.size() - sizeof(size_t), &len, sizeof(size_t));
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;
        };
              auto bytes = ser(obj.character_update_data);
              size_t len = bytes.size();
              buffer.resize(buffer.size() + sizeof(size_t));
              std::memcpy(buffer.data() + buffer.size() - sizeof(size_t), &len, sizeof(size_t));
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;
        };
            for (const auto& elem : vec) {
                auto elem_bytes = element_serializer(elem);
                size_t elem_size = elem_bytes.size();
                // increase the active buffers size so we can fit the next object in
                buffer.resize(buffer.size() + sizeof(size_t));
                // copy in the size of the object we're about to insert before that object
                std::memcpy(buffer.data() + buffer.size() - sizeof(size_t), &elem_size, sizeof(size_t));
                // dump the object in
                buffer.insert(buffer.end(), elem_bytes.begin(), elem_bytes.end());
            }
            return buffer;
        };
              auto bytes = ser(obj.id_tagged_character_update_datas);
              size_t len = bytes.size();
              buffer.resize(buffer.size() + sizeof(size_t));
              std::memcpy(buffer.data() + buffer.size() - sizeof(size_t), &len, sizeof(size_t));
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;
        };
            for (const auto& elem : vec) {
                auto elem_bytes = element_serializer(elem);
                size_t elem_size = elem_bytes.size();
                // increase the active buffers size so we can fit the next object in
                buffer.resize(buffer.size() + sizeof(size_t));
                // copy in the size of the object we're about to insert before that object
                std::memcpy(buffer.data() + buffer.size() - sizeof(size_t), &elem_size, sizeof(size_t));
                // dump the object in
                buffer.insert(buffer.end(), elem_bytes.begin(), elem_bytes.end());
            }
            return buffer;
        };
              auto bytes = ser(obj.character_update_data_time_bundles);
              size_t len = bytes.size();
              buffer.resize(buffer.size() + sizeof(size_t));
              std::memcpy(buffer.data() + buffer.size() - sizeof(size_t), &len, sizeof(size_t));
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;

    }
    size_t size_when_serialized_ClientUpdateData(const ClientUpdateData obj) {
        size_t total = 0;
            { auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              total += size_fn(obj.id); }
            { auto size_fn = [=](const std::vector<CharacterUpdateDataTimeBundle>& vec) -> size_t {
            size_t total_size = sizeof(size_t); // space for storing count
            auto element_size_func = [=](const CharacterUpdateDataTimeBundle& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [=](const std::vector<IdTaggedCharacterUpdateData>& vec) -> size_t {
            size_t total_size = sizeof(size_t); // space for storing count
            auto element_size_func = [=](const IdTaggedCharacterUpdateData& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              total += size_fn(obj.id); }
            { auto size_fn = [=](const CharacterUpdateData& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [=](const CharacterPhysicsUpdateData& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.dt); }
            { auto size_fn = [=](const ClientInputState& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.forward_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.back_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.right_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.left_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.jump_pressed); }
            return total;
        };
              total += size_fn(obj.client_input_state); }
            { auto size_fn = [](const glm::vec3 &v) { return sizeof(glm::vec3); };
              total += size_fn(obj.xy_forward_vector_camera); }
            return total;
        };
              total += size_fn(obj.character_physics_update_data); }
            { auto size_fn = [=](const CharacterCameraUpdateData& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.mouse_position_x); }
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.mouse_position_y); }
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.sensitivity); }
            return total;
        };
              total += size_fn(obj.character_camera_update_data); }
            { auto size_fn = [=](const CharacterFiringUpdateData& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.fire_pressed); }
            { auto size_fn = [=](const std::optional<DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer>& opt) -> size_t {
            size_t total_size = 1; // presence flag (1 byte)
        
            if (!opt.has_value()) {
                return total_size; // only the presence flag
            }
        
            // Value is present, delegate to inner type's size function
            auto element_size_func = [=](const DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              total += size_fn(obj.id_of_interpolation_start_game_state_id_for_non_local_character_state); }
            { auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              total += size_fn(obj.id_of_interpolation_end_game_state_id_for_non_local_character_state); }
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.interpolation_percent_when_fired); }
            return total;
        };
            total_size += element_size_func(*opt);
        
            return total_size;
        };
              total += sizeof(size_t); // length prefix
              total += size_fn(obj.data_to_reconstruct_non_local_character_physics_state_with_entity_interpolation_when_firing_on_server); }
            return total;
        };
              total += sizeof(size_t); // length prefix
              total += size_fn(obj.character_firing_update_data); }
            return total;
        };
              total += sizeof(size_t); // length prefix
              total += size_fn(obj.character_update_data); }
            return total;
        };
            for (const auto& elem : vec) {
                size_t elem_size = element_size_func(elem);
                total_size += sizeof(size_t) + elem_size; // size prefix + data
            }
            return total_size;
        };
              total += sizeof(size_t); // length prefix
              total += size_fn(obj.id_tagged_character_update_datas); }
            return total;
        };
            for (const auto& elem : vec) {
                size_t elem_size = element_size_func(elem);
                total_size += sizeof(size_t) + elem_size; // size prefix + data
            }
            return total_size;
        };
              total += sizeof(size_t); // length prefix
              total += size_fn(obj.character_update_data_time_bundles); }
            return total;

    }
    ClientUpdateData deserialize_ClientUpdateData(const std::vector<uint8_t> &buffer) {
        ClientUpdateData obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   unsigned int v;   std::memcpy(&v, buf.data(), sizeof(unsigned int));   return v; };
              auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              size_t len = size_fn(obj.id);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.id = deser(slice);
              offset += len;
            }
            { auto deser = [=](const std::vector<uint8_t>& buffer) -> std::vector<CharacterUpdateDataTimeBundle> {
            std::vector<CharacterUpdateDataTimeBundle> result;
            if (buffer.size() < sizeof(size_t)) return result;
            size_t count;
            std::memcpy(&count, buffer.data(), sizeof(size_t));
        
            size_t offset = sizeof(size_t);
            auto element_deserializer = [=](const std::vector<uint8_t> &buffer) -> CharacterUpdateDataTimeBundle {
            CharacterUpdateDataTimeBundle obj;
            size_t offset = 0;
            { auto deser = [=](const std::vector<uint8_t>& buffer) -> std::vector<IdTaggedCharacterUpdateData> {
            std::vector<IdTaggedCharacterUpdateData> result;
            if (buffer.size() < sizeof(size_t)) return result;
            size_t count;
            std::memcpy(&count, buffer.data(), sizeof(size_t));
        
            size_t offset = sizeof(size_t);
            auto element_deserializer = [=](const std::vector<uint8_t> &buffer) -> IdTaggedCharacterUpdateData {
            IdTaggedCharacterUpdateData obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   unsigned int v;   std::memcpy(&v, buf.data(), sizeof(unsigned int));   return v; };
              auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              size_t len = size_fn(obj.id);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.id = deser(slice);
              offset += len;
            }
            { auto deser = [=](const std::vector<uint8_t> &buffer) -> CharacterUpdateData {
            CharacterUpdateData obj;
            size_t offset = 0;
            { auto deser = [=](const std::vector<uint8_t> &buffer) -> CharacterPhysicsUpdateData {
            CharacterPhysicsUpdateData obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   double v;   std::memcpy(&v, buf.data(), sizeof(double));   return v; };
              auto size_fn = [](const double &v) { return sizeof(double); };
              size_t len = size_fn(obj.dt);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.dt = deser(slice);
              offset += len;
            }
            { auto deser = [=](const std::vector<uint8_t> &buffer) -> ClientInputState {
            ClientInputState obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   return buf[0] != 0; };
              auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              size_t len = size_fn(obj.forward_pressed);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.forward_pressed = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   return buf[0] != 0; };
              auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              size_t len = size_fn(obj.back_pressed);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.back_pressed = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   return buf[0] != 0; };
              auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              size_t len = size_fn(obj.right_pressed);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.right_pressed = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   return buf[0] != 0; };
              auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              size_t len = size_fn(obj.left_pressed);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.left_pressed = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   return buf[0] != 0; };
              auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              size_t len = size_fn(obj.jump_pressed);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.jump_pressed = deser(slice);
              offset += len;
            }
            return obj;
        };
              auto size_fn = [=](const ClientInputState& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.forward_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.back_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.right_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.left_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.jump_pressed); }
            return total;
        };
              size_t len = size_fn(obj.client_input_state);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.client_input_state = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   glm::vec3 v;   std::memcpy(&v, buf.data(), sizeof(glm::vec3));   return v; };
              auto size_fn = [](const glm::vec3 &v) { return sizeof(glm::vec3); };
              size_t len = size_fn(obj.xy_forward_vector_camera);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.xy_forward_vector_camera = deser(slice);
              offset += len;
            }
            return obj;
        };
              auto size_fn = [=](const CharacterPhysicsUpdateData& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.dt); }
            { auto size_fn = [=](const ClientInputState& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.forward_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.back_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.right_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.left_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.jump_pressed); }
            return total;
        };
              total += size_fn(obj.client_input_state); }
            { auto size_fn = [](const glm::vec3 &v) { return sizeof(glm::vec3); };
              total += size_fn(obj.xy_forward_vector_camera); }
            return total;
        };
              size_t len = size_fn(obj.character_physics_update_data);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.character_physics_update_data = deser(slice);
              offset += len;
            }
            { auto deser = [=](const std::vector<uint8_t> &buffer) -> CharacterCameraUpdateData {
            CharacterCameraUpdateData obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   double v;   std::memcpy(&v, buf.data(), sizeof(double));   return v; };
              auto size_fn = [](const double &v) { return sizeof(double); };
              size_t len = size_fn(obj.mouse_position_x);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.mouse_position_x = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   double v;   std::memcpy(&v, buf.data(), sizeof(double));   return v; };
              auto size_fn = [](const double &v) { return sizeof(double); };
              size_t len = size_fn(obj.mouse_position_y);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.mouse_position_y = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   double v;   std::memcpy(&v, buf.data(), sizeof(double));   return v; };
              auto size_fn = [](const double &v) { return sizeof(double); };
              size_t len = size_fn(obj.sensitivity);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.sensitivity = deser(slice);
              offset += len;
            }
            return obj;
        };
              auto size_fn = [=](const CharacterCameraUpdateData& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.mouse_position_x); }
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.mouse_position_y); }
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.sensitivity); }
            return total;
        };
              size_t len = size_fn(obj.character_camera_update_data);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.character_camera_update_data = deser(slice);
              offset += len;
            }
            { auto deser = [=](const std::vector<uint8_t> &buffer) -> CharacterFiringUpdateData {
            CharacterFiringUpdateData obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   return buf[0] != 0; };
              auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              size_t len = size_fn(obj.fire_pressed);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.fire_pressed = deser(slice);
              offset += len;
            }
            { auto deser = [=](const std::vector<uint8_t>& buffer) -> std::optional<DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer> {
            if (buffer.empty()) return std::nullopt;  // empty buffer
        
            // First byte indicates presence of value
            uint8_t has_value = buffer[0];
            if (has_value == 0) return std::nullopt;
        
            // Value is present, delegate deserialization to inner type
            auto element_deserializer = [=](const std::vector<uint8_t> &buffer) -> DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer {
            DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   unsigned int v;   std::memcpy(&v, buf.data(), sizeof(unsigned int));   return v; };
              auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              size_t len = size_fn(obj.id_of_interpolation_start_game_state_id_for_non_local_character_state);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.id_of_interpolation_start_game_state_id_for_non_local_character_state = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   unsigned int v;   std::memcpy(&v, buf.data(), sizeof(unsigned int));   return v; };
              auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              size_t len = size_fn(obj.id_of_interpolation_end_game_state_id_for_non_local_character_state);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.id_of_interpolation_end_game_state_id_for_non_local_character_state = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   double v;   std::memcpy(&v, buf.data(), sizeof(double));   return v; };
              auto size_fn = [](const double &v) { return sizeof(double); };
              size_t len = size_fn(obj.interpolation_percent_when_fired);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.interpolation_percent_when_fired = deser(slice);
              offset += len;
            }
            return obj;
        };
            std::vector<uint8_t> elem_bytes(buffer.begin() + 1, buffer.end());
            return element_deserializer(elem_bytes);
        };
              if (offset + sizeof(size_t) > buffer.size()) return obj;
              size_t len = 0;
              std::memcpy(&len, buffer.data() + offset, sizeof(size_t));
              offset += sizeof(size_t);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.data_to_reconstruct_non_local_character_physics_state_with_entity_interpolation_when_firing_on_server = deser(slice);
              offset += len;
            }
            return obj;
        };
              if (offset + sizeof(size_t) > buffer.size()) return obj;
              size_t len = 0;
              std::memcpy(&len, buffer.data() + offset, sizeof(size_t));
              offset += sizeof(size_t);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.character_firing_update_data = deser(slice);
              offset += len;
            }
            return obj;
        };
              if (offset + sizeof(size_t) > buffer.size()) return obj;
              size_t len = 0;
              std::memcpy(&len, buffer.data() + offset, sizeof(size_t));
              offset += sizeof(size_t);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.character_update_data = deser(slice);
              offset += len;
            }
            return obj;
        };
            for (size_t i = 0; i < count; ++i) {
                // element is variably sized: read elem_size first
                if (offset + sizeof(size_t) > buffer.size()) break;
                size_t elem_size;
                std::memcpy(&elem_size, buffer.data() + offset, sizeof(size_t));
                offset += sizeof(size_t);
                if (offset + elem_size > buffer.size()) break;
                std::vector<uint8_t> elem_buf(buffer.begin() + offset, buffer.begin() + offset + elem_size);
                IdTaggedCharacterUpdateData elem = element_deserializer(elem_buf);
                result.push_back(elem);
                offset += elem_size;
            }
            return result;
        };
              if (offset + sizeof(size_t) > buffer.size()) return obj;
              size_t len = 0;
              std::memcpy(&len, buffer.data() + offset, sizeof(size_t));
              offset += sizeof(size_t);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.id_tagged_character_update_datas = deser(slice);
              offset += len;
            }
            return obj;
        };
            for (size_t i = 0; i < count; ++i) {
                // element is variably sized: read elem_size first
                if (offset + sizeof(size_t) > buffer.size()) break;
                size_t elem_size;
                std::memcpy(&elem_size, buffer.data() + offset, sizeof(size_t));
                offset += sizeof(size_t);
                if (offset + elem_size > buffer.size()) break;
                std::vector<uint8_t> elem_buf(buffer.begin() + offset, buffer.begin() + offset + elem_size);
                CharacterUpdateDataTimeBundle elem = element_deserializer(elem_buf);
                result.push_back(elem);
                offset += elem_size;
            }
            return result;
        };
              if (offset + sizeof(size_t) > buffer.size()) return obj;
              size_t len = 0;
              std::memcpy(&len, buffer.data() + offset, sizeof(size_t));
              offset += sizeof(size_t);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.character_update_data_time_bundles = deser(slice);
              offset += len;
            }
            return obj;

    }
    std::string ClientUpdateDataPacket_to_string(const ClientUpdateDataPacket obj) {
        std::ostringstream oss;
            oss << "{";
            { auto conv = [=](const PacketHeader& obj) -> std::string {
            std::ostringstream oss;
            oss << "{";
            { auto conv = [=](PacketType value) -> std::string {
            switch(value) {
                case PacketType::CLIENT_UPDATE_DATA: return "PacketType::CLIENT_UPDATE_DATA";
                case PacketType::GAME_STATE: return "PacketType::GAME_STATE";
                case PacketType::NUM_ENUMERATORS: return "PacketType::NUM_ENUMERATORS";
                default: return "<unknown PacketType>";
            }
        };
              oss << "type=" << conv(obj.type); }
            oss << ", ";
            { auto conv = [](const uint32_t &v) { return std::to_string(v); };
              oss << "size_of_data_without_header=" << conv(obj.size_of_data_without_header); }
            oss << "}";
            return oss.str();
        };
              oss << "packet_header=" << conv(obj.packet_header); }
            oss << ", ";
            { auto conv = [=](const ClientUpdateData& obj) -> std::string {
            std::ostringstream oss;
            oss << "{";
            { auto conv = [](const unsigned int &v) { return std::to_string(v); };
              oss << "id=" << conv(obj.id); }
            oss << ", ";
            { auto conv = [=](const std::vector<CharacterUpdateDataTimeBundle>& vec) -> std::string {
            std::ostringstream oss;
            oss << "{";
            auto conversion = [=](const CharacterUpdateDataTimeBundle& obj) -> std::string {
            std::ostringstream oss;
            oss << "{";
            { auto conv = [=](const std::vector<IdTaggedCharacterUpdateData>& vec) -> std::string {
            std::ostringstream oss;
            oss << "{";
            auto conversion = [=](const IdTaggedCharacterUpdateData& obj) -> std::string {
            std::ostringstream oss;
            oss << "{";
            { auto conv = [](const unsigned int &v) { return std::to_string(v); };
              oss << "id=" << conv(obj.id); }
            oss << ", ";
            { auto conv = [=](const CharacterUpdateData& obj) -> std::string {
            std::ostringstream oss;
            oss << "{";
            { auto conv = [=](const CharacterPhysicsUpdateData& obj) -> std::string {
            std::ostringstream oss;
            oss << "{";
            { auto conv = [](const double &v) {  std::ostringstream oss;  oss << std::setprecision(std::numeric_limits<double>::max_digits10) << v;  return oss.str();};
              oss << "dt=" << conv(obj.dt); }
            oss << ", ";
            { auto conv = [=](const ClientInputState& obj) -> std::string {
            std::ostringstream oss;
            oss << "{";
            { auto conv = [](const bool &v) { return v ? "true" : "false"; };
              oss << "forward_pressed=" << conv(obj.forward_pressed); }
            oss << ", ";
            { auto conv = [](const bool &v) { return v ? "true" : "false"; };
              oss << "back_pressed=" << conv(obj.back_pressed); }
            oss << ", ";
            { auto conv = [](const bool &v) { return v ? "true" : "false"; };
              oss << "right_pressed=" << conv(obj.right_pressed); }
            oss << ", ";
            { auto conv = [](const bool &v) { return v ? "true" : "false"; };
              oss << "left_pressed=" << conv(obj.left_pressed); }
            oss << ", ";
            { auto conv = [](const bool &v) { return v ? "true" : "false"; };
              oss << "jump_pressed=" << conv(obj.jump_pressed); }
            oss << "}";
            return oss.str();
        };
              oss << "client_input_state=" << conv(obj.client_input_state); }
            oss << ", ";
            { auto conv = [](const glm::vec3 &v) {  int precision =  std::numeric_limits<float>::max_digits10; std::ostringstream oss; oss << std::fixed << std::setprecision(precision); oss << '(' << v.x << ',' << ' ' << v.y << ',' << ' ' << v.z <<  ')'; return oss.str();};
              oss << "xy_forward_vector_camera=" << conv(obj.xy_forward_vector_camera); }
            oss << "}";
            return oss.str();
        };
              oss << "character_physics_update_data=" << conv(obj.character_physics_update_data); }
            oss << ", ";
            { auto conv = [=](const CharacterCameraUpdateData& obj) -> std::string {
            std::ostringstream oss;
            oss << "{";
            { auto conv = [](const double &v) {  std::ostringstream oss;  oss << std::setprecision(std::numeric_limits<double>::max_digits10) << v;  return oss.str();};
              oss << "mouse_position_x=" << conv(obj.mouse_position_x); }
            oss << ", ";
            { auto conv = [](const double &v) {  std::ostringstream oss;  oss << std::setprecision(std::numeric_limits<double>::max_digits10) << v;  return oss.str();};
              oss << "mouse_position_y=" << conv(obj.mouse_position_y); }
            oss << ", ";
            { auto conv = [](const double &v) {  std::ostringstream oss;  oss << std::setprecision(std::numeric_limits<double>::max_digits10) << v;  return oss.str();};
              oss << "sensitivity=" << conv(obj.sensitivity); }
            oss << "}";
            return oss.str();
        };
              oss << "character_camera_update_data=" << conv(obj.character_camera_update_data); }
            oss << ", ";
            { auto conv = [=](const CharacterFiringUpdateData& obj) -> std::string {
            std::ostringstream oss;
            oss << "{";
            { auto conv = [](const bool &v) { return v ? "true" : "false"; };
              oss << "fire_pressed=" << conv(obj.fire_pressed); }
            oss << ", ";
            { auto conv = [=](const std::optional<DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer>& opt) -> std::string {
            if (!opt.has_value()) {
                return "std::nullopt";
            }
        
            auto conversion = [=](const DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer& obj) -> std::string {
            std::ostringstream oss;
            oss << "{";
            { auto conv = [](const unsigned int &v) { return std::to_string(v); };
              oss << "id_of_interpolation_start_game_state_id_for_non_local_character_state=" << conv(obj.id_of_interpolation_start_game_state_id_for_non_local_character_state); }
            oss << ", ";
            { auto conv = [](const unsigned int &v) { return std::to_string(v); };
              oss << "id_of_interpolation_end_game_state_id_for_non_local_character_state=" << conv(obj.id_of_interpolation_end_game_state_id_for_non_local_character_state); }
            oss << ", ";
            { auto conv = [](const double &v) {  std::ostringstream oss;  oss << std::setprecision(std::numeric_limits<double>::max_digits10) << v;  return oss.str();};
              oss << "interpolation_percent_when_fired=" << conv(obj.interpolation_percent_when_fired); }
            oss << "}";
            return oss.str();
        };
            return conversion(*opt);
        };
              oss << "data_to_reconstruct_non_local_character_physics_state_with_entity_interpolation_when_firing_on_server=" << conv(obj.data_to_reconstruct_non_local_character_physics_state_with_entity_interpolation_when_firing_on_server); }
            oss << "}";
            return oss.str();
        };
              oss << "character_firing_update_data=" << conv(obj.character_firing_update_data); }
            oss << "}";
            return oss.str();
        };
              oss << "character_update_data=" << conv(obj.character_update_data); }
            oss << "}";
            return oss.str();
        };
        
            for (size_t i = 0; i < vec.size(); ++i) {
                oss << conversion(vec[i]);
                if (i + 1 < vec.size())
                    oss << ", ";
            }
        
            oss << "}";
            return oss.str();
        };
              oss << "id_tagged_character_update_datas=" << conv(obj.id_tagged_character_update_datas); }
            oss << "}";
            return oss.str();
        };
        
            for (size_t i = 0; i < vec.size(); ++i) {
                oss << conversion(vec[i]);
                if (i + 1 < vec.size())
                    oss << ", ";
            }
        
            oss << "}";
            return oss.str();
        };
              oss << "character_update_data_time_bundles=" << conv(obj.character_update_data_time_bundles); }
            oss << "}";
            return oss.str();
        };
              oss << "client_update_data=" << conv(obj.client_update_data); }
            oss << "}";
            return oss.str();

    }
    ClientUpdateDataPacket string_to_ClientUpdateDataPacket(const std::string &s) {
        ClientUpdateDataPacket obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &s) -> PacketHeader {
            PacketHeader obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &s) -> PacketType {
            if (s == "PacketType::CLIENT_UPDATE_DATA") return PacketType::CLIENT_UPDATE_DATA;
            if (s == "PacketType::GAME_STATE") return PacketType::GAME_STATE;
            if (s == "PacketType::NUM_ENUMERATORS") return PacketType::NUM_ENUMERATORS;
            return static_cast<PacketType>(0); // default fallback
        };
                    obj.type = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return static_cast<uint32_t>(std::stoul(s)); };
                    obj.size_of_data_without_header = conv(value_str);
                }
            }
            return obj;
        };
                    obj.packet_header = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &s) -> ClientUpdateData {
            ClientUpdateData obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return static_cast<unsigned int>(std::stoul(s)); };
                    obj.id = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &input) -> std::vector<CharacterUpdateDataTimeBundle> {
            std::string trimmed = input;
            if (!trimmed.empty() && trimmed.front() == '{' && trimmed.back() == '}') {
                trimmed = trimmed.substr(1, trimmed.size() - 2);
            }
        
            std::vector<CharacterUpdateDataTimeBundle> result;
            std::regex element_re(R"(.*)");
            auto begin = std::sregex_iterator(trimmed.begin(), trimmed.end(), element_re);
            auto end = std::sregex_iterator();
        
            for (auto it = begin; it != end; ++it) {
                try {
                    auto conversion = [=](const std::string &s) -> CharacterUpdateDataTimeBundle {
            CharacterUpdateDataTimeBundle obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &input) -> std::vector<IdTaggedCharacterUpdateData> {
            std::string trimmed = input;
            if (!trimmed.empty() && trimmed.front() == '{' && trimmed.back() == '}') {
                trimmed = trimmed.substr(1, trimmed.size() - 2);
            }
        
            std::vector<IdTaggedCharacterUpdateData> result;
            std::regex element_re(R"(.*)");
            auto begin = std::sregex_iterator(trimmed.begin(), trimmed.end(), element_re);
            auto end = std::sregex_iterator();
        
            for (auto it = begin; it != end; ++it) {
                try {
                    auto conversion = [=](const std::string &s) -> IdTaggedCharacterUpdateData {
            IdTaggedCharacterUpdateData obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return static_cast<unsigned int>(std::stoul(s)); };
                    obj.id = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &s) -> CharacterUpdateData {
            CharacterUpdateData obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &s) -> CharacterPhysicsUpdateData {
            CharacterPhysicsUpdateData obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return std::stod(s); };
                    obj.dt = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &s) -> ClientInputState {
            ClientInputState obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return s == "true"; };
                    obj.forward_pressed = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return s == "true"; };
                    obj.back_pressed = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return s == "true"; };
                    obj.right_pressed = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return s == "true"; };
                    obj.left_pressed = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return s == "true"; };
                    obj.jump_pressed = conv(value_str);
                }
            }
            return obj;
        };
                    obj.client_input_state = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) {   std::regex r(R"(\s*\(?\s*([-+]?[0-9]*\.?[0-9]+)\s*,\s*([-+]?[0-9]*\.?[0-9]+)\s*,\s*([-+]?[0-9]*\.?[0-9]+)\s*\)?\s*)");   std::smatch m;   if (std::regex_match(s, m, r)) {     return glm::vec3(std::stof(m[1]), std::stof(m[2]), std::stof(m[3]));   }   throw std::invalid_argument("Invalid glm::vec3 string"); };
                    obj.xy_forward_vector_camera = conv(value_str);
                }
            }
            return obj;
        };
                    obj.character_physics_update_data = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &s) -> CharacterCameraUpdateData {
            CharacterCameraUpdateData obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return std::stod(s); };
                    obj.mouse_position_x = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return std::stod(s); };
                    obj.mouse_position_y = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return std::stod(s); };
                    obj.sensitivity = conv(value_str);
                }
            }
            return obj;
        };
                    obj.character_camera_update_data = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &s) -> CharacterFiringUpdateData {
            CharacterFiringUpdateData obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return s == "true"; };
                    obj.fire_pressed = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &input) -> std::optional<DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer> {
            std::string trimmed = input;
            // Trim whitespace
            trimmed.erase(0, trimmed.find_first_not_of(" \t\n\r"));
            trimmed.erase(trimmed.find_last_not_of(" \t\n\r") + 1);
        
            // Explicit representation of null:
            if (trimmed == "std::nullopt") {
                return std::nullopt;
            }
        
            // Try matching actual value
            std::regex element_re(R"(.*)");
            std::smatch match;
        
            if (std::regex_match(trimmed, match, element_re)) {
                try {
                    auto conversion = [=](const std::string &s) -> DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer {
            DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return static_cast<unsigned int>(std::stoul(s)); };
                    obj.id_of_interpolation_start_game_state_id_for_non_local_character_state = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return static_cast<unsigned int>(std::stoul(s)); };
                    obj.id_of_interpolation_end_game_state_id_for_non_local_character_state = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return std::stod(s); };
                    obj.interpolation_percent_when_fired = conv(value_str);
                }
            }
            return obj;
        };
                    return conversion(trimmed);
                } catch (...) {
                    return std::nullopt;
                }
            }
        
            // Anything else is treated as nullopt
            return std::nullopt;
        };
                    obj.data_to_reconstruct_non_local_character_physics_state_with_entity_interpolation_when_firing_on_server = conv(value_str);
                }
            }
            return obj;
        };
                    obj.character_firing_update_data = conv(value_str);
                }
            }
            return obj;
        };
                    obj.character_update_data = conv(value_str);
                }
            }
            return obj;
        };
                    result.push_back(conversion(it->str()));
                } catch (...) {
                    // Ignore malformed elements
                }
            }
            return result;
        };
                    obj.id_tagged_character_update_datas = conv(value_str);
                }
            }
            return obj;
        };
                    result.push_back(conversion(it->str()));
                } catch (...) {
                    // Ignore malformed elements
                }
            }
            return result;
        };
                    obj.character_update_data_time_bundles = conv(value_str);
                }
            }
            return obj;
        };
                    obj.client_update_data = conv(value_str);
                }
            }
            return obj;

    }
    std::vector<uint8_t> serialize_ClientUpdateDataPacket(const ClientUpdateDataPacket obj) {
        std::vector<uint8_t> buffer;
            { auto ser = [=](const PacketHeader& obj) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            { auto ser = [=](PacketType value) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer(sizeof(uint8_t));
            uint8_t raw = static_cast<uint8_t>(value);
            std::memcpy(buffer.data(), &raw, sizeof(uint8_t));
            return buffer;
        };
              auto bytes = ser(obj.type);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const uint32_t &v) {   std::vector<uint8_t> buf(sizeof(uint32_t));   std::memcpy(buf.data(), &v, sizeof(uint32_t));   return buf; };
              auto bytes = ser(obj.size_of_data_without_header);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;
        };
              auto bytes = ser(obj.packet_header);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [=](const ClientUpdateData& obj) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            { auto ser = [](const unsigned int &v) {   std::vector<uint8_t> buf(sizeof(unsigned int));   std::memcpy(buf.data(), &v, sizeof(unsigned int));   return buf; };
              auto bytes = ser(obj.id);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [=](const std::vector<CharacterUpdateDataTimeBundle>& vec) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            // store vector size first, which is necessary or else we won't know when to stop during deserialization
            size_t count = vec.size();
            buffer.resize(sizeof(size_t));
            std::memcpy(buffer.data(), &count, sizeof(size_t));
        
            auto element_serializer = [=](const CharacterUpdateDataTimeBundle& obj) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            { auto ser = [=](const std::vector<IdTaggedCharacterUpdateData>& vec) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            // store vector size first, which is necessary or else we won't know when to stop during deserialization
            size_t count = vec.size();
            buffer.resize(sizeof(size_t));
            std::memcpy(buffer.data(), &count, sizeof(size_t));
        
            auto element_serializer = [=](const IdTaggedCharacterUpdateData& obj) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            { auto ser = [](const unsigned int &v) {   std::vector<uint8_t> buf(sizeof(unsigned int));   std::memcpy(buf.data(), &v, sizeof(unsigned int));   return buf; };
              auto bytes = ser(obj.id);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [=](const CharacterUpdateData& obj) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            { auto ser = [=](const CharacterPhysicsUpdateData& obj) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            { auto ser = [](const double &v) {   std::vector<uint8_t> buf(sizeof(double));   std::memcpy(buf.data(), &v, sizeof(double));   return buf; };
              auto bytes = ser(obj.dt);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [=](const ClientInputState& obj) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            { auto ser = [](const bool &v) {   std::vector<uint8_t> buf(1);   buf[0] = v ? 1 : 0;   return buf; };
              auto bytes = ser(obj.forward_pressed);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const bool &v) {   std::vector<uint8_t> buf(1);   buf[0] = v ? 1 : 0;   return buf; };
              auto bytes = ser(obj.back_pressed);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const bool &v) {   std::vector<uint8_t> buf(1);   buf[0] = v ? 1 : 0;   return buf; };
              auto bytes = ser(obj.right_pressed);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const bool &v) {   std::vector<uint8_t> buf(1);   buf[0] = v ? 1 : 0;   return buf; };
              auto bytes = ser(obj.left_pressed);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const bool &v) {   std::vector<uint8_t> buf(1);   buf[0] = v ? 1 : 0;   return buf; };
              auto bytes = ser(obj.jump_pressed);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;
        };
              auto bytes = ser(obj.client_input_state);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const glm::vec3 &v) {   std::vector<uint8_t> buf(sizeof(glm::vec3));   std::memcpy(buf.data(), &v, sizeof(glm::vec3));   return buf; };
              auto bytes = ser(obj.xy_forward_vector_camera);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;
        };
              auto bytes = ser(obj.character_physics_update_data);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [=](const CharacterCameraUpdateData& obj) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            { auto ser = [](const double &v) {   std::vector<uint8_t> buf(sizeof(double));   std::memcpy(buf.data(), &v, sizeof(double));   return buf; };
              auto bytes = ser(obj.mouse_position_x);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const double &v) {   std::vector<uint8_t> buf(sizeof(double));   std::memcpy(buf.data(), &v, sizeof(double));   return buf; };
              auto bytes = ser(obj.mouse_position_y);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const double &v) {   std::vector<uint8_t> buf(sizeof(double));   std::memcpy(buf.data(), &v, sizeof(double));   return buf; };
              auto bytes = ser(obj.sensitivity);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;
        };
              auto bytes = ser(obj.character_camera_update_data);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [=](const CharacterFiringUpdateData& obj) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            { auto ser = [](const bool &v) {   std::vector<uint8_t> buf(1);   buf[0] = v ? 1 : 0;   return buf; };
              auto bytes = ser(obj.fire_pressed);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [=](const std::optional<DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer>& opt) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
        
            // First byte: 0 = nullopt, 1 = value present
            if (!opt.has_value()) {
                buffer.push_back(0);
                return buffer;
            }
        
            buffer.push_back(1); // value present
            auto element_serializer = [=](const DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer& obj) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            { auto ser = [](const unsigned int &v) {   std::vector<uint8_t> buf(sizeof(unsigned int));   std::memcpy(buf.data(), &v, sizeof(unsigned int));   return buf; };
              auto bytes = ser(obj.id_of_interpolation_start_game_state_id_for_non_local_character_state);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const unsigned int &v) {   std::vector<uint8_t> buf(sizeof(unsigned int));   std::memcpy(buf.data(), &v, sizeof(unsigned int));   return buf; };
              auto bytes = ser(obj.id_of_interpolation_end_game_state_id_for_non_local_character_state);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const double &v) {   std::vector<uint8_t> buf(sizeof(double));   std::memcpy(buf.data(), &v, sizeof(double));   return buf; };
              auto bytes = ser(obj.interpolation_percent_when_fired);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;
        };
            auto elem_bytes = element_serializer(*opt);
            buffer.insert(buffer.end(), elem_bytes.begin(), elem_bytes.end());
        
            return buffer;
        };
              auto bytes = ser(obj.data_to_reconstruct_non_local_character_physics_state_with_entity_interpolation_when_firing_on_server);
              size_t len = bytes.size();
              buffer.resize(buffer.size() + sizeof(size_t));
              std::memcpy(buffer.data() + buffer.size() - sizeof(size_t), &len, sizeof(size_t));
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;
        };
              auto bytes = ser(obj.character_firing_update_data);
              size_t len = bytes.size();
              buffer.resize(buffer.size() + sizeof(size_t));
              std::memcpy(buffer.data() + buffer.size() - sizeof(size_t), &len, sizeof(size_t));
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;
        };
              auto bytes = ser(obj.character_update_data);
              size_t len = bytes.size();
              buffer.resize(buffer.size() + sizeof(size_t));
              std::memcpy(buffer.data() + buffer.size() - sizeof(size_t), &len, sizeof(size_t));
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;
        };
            for (const auto& elem : vec) {
                auto elem_bytes = element_serializer(elem);
                size_t elem_size = elem_bytes.size();
                // increase the active buffers size so we can fit the next object in
                buffer.resize(buffer.size() + sizeof(size_t));
                // copy in the size of the object we're about to insert before that object
                std::memcpy(buffer.data() + buffer.size() - sizeof(size_t), &elem_size, sizeof(size_t));
                // dump the object in
                buffer.insert(buffer.end(), elem_bytes.begin(), elem_bytes.end());
            }
            return buffer;
        };
              auto bytes = ser(obj.id_tagged_character_update_datas);
              size_t len = bytes.size();
              buffer.resize(buffer.size() + sizeof(size_t));
              std::memcpy(buffer.data() + buffer.size() - sizeof(size_t), &len, sizeof(size_t));
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;
        };
            for (const auto& elem : vec) {
                auto elem_bytes = element_serializer(elem);
                size_t elem_size = elem_bytes.size();
                // increase the active buffers size so we can fit the next object in
                buffer.resize(buffer.size() + sizeof(size_t));
                // copy in the size of the object we're about to insert before that object
                std::memcpy(buffer.data() + buffer.size() - sizeof(size_t), &elem_size, sizeof(size_t));
                // dump the object in
                buffer.insert(buffer.end(), elem_bytes.begin(), elem_bytes.end());
            }
            return buffer;
        };
              auto bytes = ser(obj.character_update_data_time_bundles);
              size_t len = bytes.size();
              buffer.resize(buffer.size() + sizeof(size_t));
              std::memcpy(buffer.data() + buffer.size() - sizeof(size_t), &len, sizeof(size_t));
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;
        };
              auto bytes = ser(obj.client_update_data);
              size_t len = bytes.size();
              buffer.resize(buffer.size() + sizeof(size_t));
              std::memcpy(buffer.data() + buffer.size() - sizeof(size_t), &len, sizeof(size_t));
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;

    }
    size_t size_when_serialized_ClientUpdateDataPacket(const ClientUpdateDataPacket obj) {
        size_t total = 0;
            { auto size_fn = [=](const PacketHeader& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [=](const PacketType &obj) -> size_t {
            return sizeof(uint8_t);
        };
              total += size_fn(obj.type); }
            { auto size_fn = [](const uint32_t &v) { return sizeof(uint32_t); };
              total += size_fn(obj.size_of_data_without_header); }
            return total;
        };
              total += size_fn(obj.packet_header); }
            { auto size_fn = [=](const ClientUpdateData& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              total += size_fn(obj.id); }
            { auto size_fn = [=](const std::vector<CharacterUpdateDataTimeBundle>& vec) -> size_t {
            size_t total_size = sizeof(size_t); // space for storing count
            auto element_size_func = [=](const CharacterUpdateDataTimeBundle& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [=](const std::vector<IdTaggedCharacterUpdateData>& vec) -> size_t {
            size_t total_size = sizeof(size_t); // space for storing count
            auto element_size_func = [=](const IdTaggedCharacterUpdateData& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              total += size_fn(obj.id); }
            { auto size_fn = [=](const CharacterUpdateData& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [=](const CharacterPhysicsUpdateData& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.dt); }
            { auto size_fn = [=](const ClientInputState& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.forward_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.back_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.right_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.left_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.jump_pressed); }
            return total;
        };
              total += size_fn(obj.client_input_state); }
            { auto size_fn = [](const glm::vec3 &v) { return sizeof(glm::vec3); };
              total += size_fn(obj.xy_forward_vector_camera); }
            return total;
        };
              total += size_fn(obj.character_physics_update_data); }
            { auto size_fn = [=](const CharacterCameraUpdateData& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.mouse_position_x); }
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.mouse_position_y); }
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.sensitivity); }
            return total;
        };
              total += size_fn(obj.character_camera_update_data); }
            { auto size_fn = [=](const CharacterFiringUpdateData& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.fire_pressed); }
            { auto size_fn = [=](const std::optional<DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer>& opt) -> size_t {
            size_t total_size = 1; // presence flag (1 byte)
        
            if (!opt.has_value()) {
                return total_size; // only the presence flag
            }
        
            // Value is present, delegate to inner type's size function
            auto element_size_func = [=](const DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              total += size_fn(obj.id_of_interpolation_start_game_state_id_for_non_local_character_state); }
            { auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              total += size_fn(obj.id_of_interpolation_end_game_state_id_for_non_local_character_state); }
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.interpolation_percent_when_fired); }
            return total;
        };
            total_size += element_size_func(*opt);
        
            return total_size;
        };
              total += sizeof(size_t); // length prefix
              total += size_fn(obj.data_to_reconstruct_non_local_character_physics_state_with_entity_interpolation_when_firing_on_server); }
            return total;
        };
              total += sizeof(size_t); // length prefix
              total += size_fn(obj.character_firing_update_data); }
            return total;
        };
              total += sizeof(size_t); // length prefix
              total += size_fn(obj.character_update_data); }
            return total;
        };
            for (const auto& elem : vec) {
                size_t elem_size = element_size_func(elem);
                total_size += sizeof(size_t) + elem_size; // size prefix + data
            }
            return total_size;
        };
              total += sizeof(size_t); // length prefix
              total += size_fn(obj.id_tagged_character_update_datas); }
            return total;
        };
            for (const auto& elem : vec) {
                size_t elem_size = element_size_func(elem);
                total_size += sizeof(size_t) + elem_size; // size prefix + data
            }
            return total_size;
        };
              total += sizeof(size_t); // length prefix
              total += size_fn(obj.character_update_data_time_bundles); }
            return total;
        };
              total += sizeof(size_t); // length prefix
              total += size_fn(obj.client_update_data); }
            return total;

    }
    ClientUpdateDataPacket deserialize_ClientUpdateDataPacket(const std::vector<uint8_t> &buffer) {
        ClientUpdateDataPacket obj;
            size_t offset = 0;
            { auto deser = [=](const std::vector<uint8_t> &buffer) -> PacketHeader {
            PacketHeader obj;
            size_t offset = 0;
            { auto deser = [=](const std::vector<uint8_t> &buffer) -> PacketType {
            if (buffer.size() < sizeof(uint8_t)) return static_cast<PacketType>(0);
            uint8_t raw = 0;
            std::memcpy(&raw, buffer.data(), sizeof(uint8_t));
            return static_cast<PacketType>(raw);
        };
              auto size_fn = [=](const PacketType &obj) -> size_t {
            return sizeof(uint8_t);
        };
              size_t len = size_fn(obj.type);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.type = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   uint32_t v;   std::memcpy(&v, buf.data(), sizeof(uint32_t));   return v; };
              auto size_fn = [](const uint32_t &v) { return sizeof(uint32_t); };
              size_t len = size_fn(obj.size_of_data_without_header);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.size_of_data_without_header = deser(slice);
              offset += len;
            }
            return obj;
        };
              auto size_fn = [=](const PacketHeader& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [=](const PacketType &obj) -> size_t {
            return sizeof(uint8_t);
        };
              total += size_fn(obj.type); }
            { auto size_fn = [](const uint32_t &v) { return sizeof(uint32_t); };
              total += size_fn(obj.size_of_data_without_header); }
            return total;
        };
              size_t len = size_fn(obj.packet_header);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.packet_header = deser(slice);
              offset += len;
            }
            { auto deser = [=](const std::vector<uint8_t> &buffer) -> ClientUpdateData {
            ClientUpdateData obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   unsigned int v;   std::memcpy(&v, buf.data(), sizeof(unsigned int));   return v; };
              auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              size_t len = size_fn(obj.id);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.id = deser(slice);
              offset += len;
            }
            { auto deser = [=](const std::vector<uint8_t>& buffer) -> std::vector<CharacterUpdateDataTimeBundle> {
            std::vector<CharacterUpdateDataTimeBundle> result;
            if (buffer.size() < sizeof(size_t)) return result;
            size_t count;
            std::memcpy(&count, buffer.data(), sizeof(size_t));
        
            size_t offset = sizeof(size_t);
            auto element_deserializer = [=](const std::vector<uint8_t> &buffer) -> CharacterUpdateDataTimeBundle {
            CharacterUpdateDataTimeBundle obj;
            size_t offset = 0;
            { auto deser = [=](const std::vector<uint8_t>& buffer) -> std::vector<IdTaggedCharacterUpdateData> {
            std::vector<IdTaggedCharacterUpdateData> result;
            if (buffer.size() < sizeof(size_t)) return result;
            size_t count;
            std::memcpy(&count, buffer.data(), sizeof(size_t));
        
            size_t offset = sizeof(size_t);
            auto element_deserializer = [=](const std::vector<uint8_t> &buffer) -> IdTaggedCharacterUpdateData {
            IdTaggedCharacterUpdateData obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   unsigned int v;   std::memcpy(&v, buf.data(), sizeof(unsigned int));   return v; };
              auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              size_t len = size_fn(obj.id);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.id = deser(slice);
              offset += len;
            }
            { auto deser = [=](const std::vector<uint8_t> &buffer) -> CharacterUpdateData {
            CharacterUpdateData obj;
            size_t offset = 0;
            { auto deser = [=](const std::vector<uint8_t> &buffer) -> CharacterPhysicsUpdateData {
            CharacterPhysicsUpdateData obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   double v;   std::memcpy(&v, buf.data(), sizeof(double));   return v; };
              auto size_fn = [](const double &v) { return sizeof(double); };
              size_t len = size_fn(obj.dt);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.dt = deser(slice);
              offset += len;
            }
            { auto deser = [=](const std::vector<uint8_t> &buffer) -> ClientInputState {
            ClientInputState obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   return buf[0] != 0; };
              auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              size_t len = size_fn(obj.forward_pressed);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.forward_pressed = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   return buf[0] != 0; };
              auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              size_t len = size_fn(obj.back_pressed);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.back_pressed = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   return buf[0] != 0; };
              auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              size_t len = size_fn(obj.right_pressed);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.right_pressed = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   return buf[0] != 0; };
              auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              size_t len = size_fn(obj.left_pressed);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.left_pressed = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   return buf[0] != 0; };
              auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              size_t len = size_fn(obj.jump_pressed);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.jump_pressed = deser(slice);
              offset += len;
            }
            return obj;
        };
              auto size_fn = [=](const ClientInputState& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.forward_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.back_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.right_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.left_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.jump_pressed); }
            return total;
        };
              size_t len = size_fn(obj.client_input_state);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.client_input_state = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   glm::vec3 v;   std::memcpy(&v, buf.data(), sizeof(glm::vec3));   return v; };
              auto size_fn = [](const glm::vec3 &v) { return sizeof(glm::vec3); };
              size_t len = size_fn(obj.xy_forward_vector_camera);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.xy_forward_vector_camera = deser(slice);
              offset += len;
            }
            return obj;
        };
              auto size_fn = [=](const CharacterPhysicsUpdateData& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.dt); }
            { auto size_fn = [=](const ClientInputState& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.forward_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.back_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.right_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.left_pressed); }
            { auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              total += size_fn(obj.jump_pressed); }
            return total;
        };
              total += size_fn(obj.client_input_state); }
            { auto size_fn = [](const glm::vec3 &v) { return sizeof(glm::vec3); };
              total += size_fn(obj.xy_forward_vector_camera); }
            return total;
        };
              size_t len = size_fn(obj.character_physics_update_data);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.character_physics_update_data = deser(slice);
              offset += len;
            }
            { auto deser = [=](const std::vector<uint8_t> &buffer) -> CharacterCameraUpdateData {
            CharacterCameraUpdateData obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   double v;   std::memcpy(&v, buf.data(), sizeof(double));   return v; };
              auto size_fn = [](const double &v) { return sizeof(double); };
              size_t len = size_fn(obj.mouse_position_x);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.mouse_position_x = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   double v;   std::memcpy(&v, buf.data(), sizeof(double));   return v; };
              auto size_fn = [](const double &v) { return sizeof(double); };
              size_t len = size_fn(obj.mouse_position_y);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.mouse_position_y = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   double v;   std::memcpy(&v, buf.data(), sizeof(double));   return v; };
              auto size_fn = [](const double &v) { return sizeof(double); };
              size_t len = size_fn(obj.sensitivity);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.sensitivity = deser(slice);
              offset += len;
            }
            return obj;
        };
              auto size_fn = [=](const CharacterCameraUpdateData& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.mouse_position_x); }
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.mouse_position_y); }
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.sensitivity); }
            return total;
        };
              size_t len = size_fn(obj.character_camera_update_data);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.character_camera_update_data = deser(slice);
              offset += len;
            }
            { auto deser = [=](const std::vector<uint8_t> &buffer) -> CharacterFiringUpdateData {
            CharacterFiringUpdateData obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   return buf[0] != 0; };
              auto size_fn = [](const bool &v) { return sizeof(uint8_t); };
              size_t len = size_fn(obj.fire_pressed);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.fire_pressed = deser(slice);
              offset += len;
            }
            { auto deser = [=](const std::vector<uint8_t>& buffer) -> std::optional<DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer> {
            if (buffer.empty()) return std::nullopt;  // empty buffer
        
            // First byte indicates presence of value
            uint8_t has_value = buffer[0];
            if (has_value == 0) return std::nullopt;
        
            // Value is present, delegate deserialization to inner type
            auto element_deserializer = [=](const std::vector<uint8_t> &buffer) -> DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer {
            DataToReconstructNonLocalCharacterPhysicsStateWithEntityInterpolationWhenFiringOnServer obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   unsigned int v;   std::memcpy(&v, buf.data(), sizeof(unsigned int));   return v; };
              auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              size_t len = size_fn(obj.id_of_interpolation_start_game_state_id_for_non_local_character_state);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.id_of_interpolation_start_game_state_id_for_non_local_character_state = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   unsigned int v;   std::memcpy(&v, buf.data(), sizeof(unsigned int));   return v; };
              auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              size_t len = size_fn(obj.id_of_interpolation_end_game_state_id_for_non_local_character_state);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.id_of_interpolation_end_game_state_id_for_non_local_character_state = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   double v;   std::memcpy(&v, buf.data(), sizeof(double));   return v; };
              auto size_fn = [](const double &v) { return sizeof(double); };
              size_t len = size_fn(obj.interpolation_percent_when_fired);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.interpolation_percent_when_fired = deser(slice);
              offset += len;
            }
            return obj;
        };
            std::vector<uint8_t> elem_bytes(buffer.begin() + 1, buffer.end());
            return element_deserializer(elem_bytes);
        };
              if (offset + sizeof(size_t) > buffer.size()) return obj;
              size_t len = 0;
              std::memcpy(&len, buffer.data() + offset, sizeof(size_t));
              offset += sizeof(size_t);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.data_to_reconstruct_non_local_character_physics_state_with_entity_interpolation_when_firing_on_server = deser(slice);
              offset += len;
            }
            return obj;
        };
              if (offset + sizeof(size_t) > buffer.size()) return obj;
              size_t len = 0;
              std::memcpy(&len, buffer.data() + offset, sizeof(size_t));
              offset += sizeof(size_t);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.character_firing_update_data = deser(slice);
              offset += len;
            }
            return obj;
        };
              if (offset + sizeof(size_t) > buffer.size()) return obj;
              size_t len = 0;
              std::memcpy(&len, buffer.data() + offset, sizeof(size_t));
              offset += sizeof(size_t);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.character_update_data = deser(slice);
              offset += len;
            }
            return obj;
        };
            for (size_t i = 0; i < count; ++i) {
                // element is variably sized: read elem_size first
                if (offset + sizeof(size_t) > buffer.size()) break;
                size_t elem_size;
                std::memcpy(&elem_size, buffer.data() + offset, sizeof(size_t));
                offset += sizeof(size_t);
                if (offset + elem_size > buffer.size()) break;
                std::vector<uint8_t> elem_buf(buffer.begin() + offset, buffer.begin() + offset + elem_size);
                IdTaggedCharacterUpdateData elem = element_deserializer(elem_buf);
                result.push_back(elem);
                offset += elem_size;
            }
            return result;
        };
              if (offset + sizeof(size_t) > buffer.size()) return obj;
              size_t len = 0;
              std::memcpy(&len, buffer.data() + offset, sizeof(size_t));
              offset += sizeof(size_t);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.id_tagged_character_update_datas = deser(slice);
              offset += len;
            }
            return obj;
        };
            for (size_t i = 0; i < count; ++i) {
                // element is variably sized: read elem_size first
                if (offset + sizeof(size_t) > buffer.size()) break;
                size_t elem_size;
                std::memcpy(&elem_size, buffer.data() + offset, sizeof(size_t));
                offset += sizeof(size_t);
                if (offset + elem_size > buffer.size()) break;
                std::vector<uint8_t> elem_buf(buffer.begin() + offset, buffer.begin() + offset + elem_size);
                CharacterUpdateDataTimeBundle elem = element_deserializer(elem_buf);
                result.push_back(elem);
                offset += elem_size;
            }
            return result;
        };
              if (offset + sizeof(size_t) > buffer.size()) return obj;
              size_t len = 0;
              std::memcpy(&len, buffer.data() + offset, sizeof(size_t));
              offset += sizeof(size_t);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.character_update_data_time_bundles = deser(slice);
              offset += len;
            }
            return obj;
        };
              if (offset + sizeof(size_t) > buffer.size()) return obj;
              size_t len = 0;
              std::memcpy(&len, buffer.data() + offset, sizeof(size_t));
              offset += sizeof(size_t);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.client_update_data = deser(slice);
              offset += len;
            }
            return obj;

    }
    std::string GameState_to_string(const GameState obj) {
        std::ostringstream oss;
            oss << "{";
            { auto conv = [](const unsigned int &v) { return std::to_string(v); };
              oss << "id=" << conv(obj.id); }
            oss << ", ";
            { auto conv = [=](const IdTaggedCharacterPhysicsState& obj) -> std::string {
            std::ostringstream oss;
            oss << "{";
            { auto conv = [](const unsigned int &v) { return std::to_string(v); };
              oss << "id_of_last_update_data_used_to_produce_this_state=" << conv(obj.id_of_last_update_data_used_to_produce_this_state); }
            oss << ", ";
            { auto conv = [=](const CharacterPhysicsState& obj) -> std::string {
            std::ostringstream oss;
            oss << "{";
            { auto conv = [](const JPH::Vec3 &v) {   std::ostringstream oss;   oss << std::setprecision(std::numeric_limits<float>::max_digits10) << std::fixed;   oss << '(' << v.GetX() << ", " << v.GetY() << ", " << v.GetZ() << ')';   return oss.str(); };
              oss << "position=" << conv(obj.position); }
            oss << ", ";
            { auto conv = [](const JPH::Vec3 &v) {   std::ostringstream oss;   oss << std::setprecision(std::numeric_limits<float>::max_digits10) << std::fixed;   oss << '(' << v.GetX() << ", " << v.GetY() << ", " << v.GetZ() << ')';   return oss.str(); };
              oss << "velocity=" << conv(obj.velocity); }
            oss << "}";
            return oss.str();
        };
              oss << "character_physics_state=" << conv(obj.character_physics_state); }
            oss << "}";
            return oss.str();
        };
              oss << "id_tagged_character_physics_state=" << conv(obj.id_tagged_character_physics_state); }
            oss << ", ";
            { auto conv = [=](const IdTaggedCharacterCameraState& obj) -> std::string {
            std::ostringstream oss;
            oss << "{";
            { auto conv = [](const unsigned int &v) { return std::to_string(v); };
              oss << "id_of_last_update_data_used_to_produce_this_state=" << conv(obj.id_of_last_update_data_used_to_produce_this_state); }
            oss << ", ";
            { auto conv = [=](const CharacterCameraState& obj) -> std::string {
            std::ostringstream oss;
            oss << "{";
            { auto conv = [](const double &v) {  std::ostringstream oss;  oss << std::setprecision(std::numeric_limits<double>::max_digits10) << v;  return oss.str();};
              oss << "yaw=" << conv(obj.yaw); }
            oss << ", ";
            { auto conv = [](const double &v) {  std::ostringstream oss;  oss << std::setprecision(std::numeric_limits<double>::max_digits10) << v;  return oss.str();};
              oss << "pitch=" << conv(obj.pitch); }
            oss << ", ";
            { auto conv = [](const double &v) {  std::ostringstream oss;  oss << std::setprecision(std::numeric_limits<double>::max_digits10) << v;  return oss.str();};
              oss << "last_mouse_position_x=" << conv(obj.last_mouse_position_x); }
            oss << ", ";
            { auto conv = [](const double &v) {  std::ostringstream oss;  oss << std::setprecision(std::numeric_limits<double>::max_digits10) << v;  return oss.str();};
              oss << "last_mouse_position_y=" << conv(obj.last_mouse_position_y); }
            oss << "}";
            return oss.str();
        };
              oss << "character_camera_state=" << conv(obj.character_camera_state); }
            oss << "}";
            return oss.str();
        };
              oss << "id_tagged_character_camera_state=" << conv(obj.id_tagged_character_camera_state); }
            oss << ", ";
            { auto conv = [=](const CharacterPhysicsState& obj) -> std::string {
            std::ostringstream oss;
            oss << "{";
            { auto conv = [](const JPH::Vec3 &v) {   std::ostringstream oss;   oss << std::setprecision(std::numeric_limits<float>::max_digits10) << std::fixed;   oss << '(' << v.GetX() << ", " << v.GetY() << ", " << v.GetZ() << ')';   return oss.str(); };
              oss << "position=" << conv(obj.position); }
            oss << ", ";
            { auto conv = [](const JPH::Vec3 &v) {   std::ostringstream oss;   oss << std::setprecision(std::numeric_limits<float>::max_digits10) << std::fixed;   oss << '(' << v.GetX() << ", " << v.GetY() << ", " << v.GetZ() << ')';   return oss.str(); };
              oss << "velocity=" << conv(obj.velocity); }
            oss << "}";
            return oss.str();
        };
              oss << "target_physics_state=" << conv(obj.target_physics_state); }
            oss << ", ";
            { auto conv = [=](const std::vector<SoundType>& vec) -> std::string {
            std::ostringstream oss;
            oss << "{";
            auto conversion = [=](SoundType value) -> std::string {
            switch(value) {
                case SoundType::UI_HOVER: return "SoundType::UI_HOVER";
                case SoundType::UI_CLICK: return "SoundType::UI_CLICK";
                case SoundType::UI_SUCCESS: return "SoundType::UI_SUCCESS";
                case SoundType::CLIENT_HIT: return "SoundType::CLIENT_HIT";
                case SoundType::CLIENT_MISS: return "SoundType::CLIENT_MISS";
                case SoundType::SERVER_HIT: return "SoundType::SERVER_HIT";
                case SoundType::SERVER_MISS: return "SoundType::SERVER_MISS";
                default: return "<unknown SoundType>";
            }
        };
        
            for (size_t i = 0; i < vec.size(); ++i) {
                oss << conversion(vec[i]);
                if (i + 1 < vec.size())
                    oss << ", ";
            }
        
            oss << "}";
            return oss.str();
        };
              oss << "sounds=" << conv(obj.sounds); }
            oss << "}";
            return oss.str();

    }
    GameState string_to_GameState(const std::string &s) {
        GameState obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return static_cast<unsigned int>(std::stoul(s)); };
                    obj.id = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &s) -> IdTaggedCharacterPhysicsState {
            IdTaggedCharacterPhysicsState obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return static_cast<unsigned int>(std::stoul(s)); };
                    obj.id_of_last_update_data_used_to_produce_this_state = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &s) -> CharacterPhysicsState {
            CharacterPhysicsState obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) {   std::regex r(R"(\s*\(?\s*([-+]?[0-9]*\.?[0-9]+)\s*,\s*([-+]?[0-9]*\.?[0-9]+)\s*,\s*([-+]?[0-9]*\.?[0-9]+)\s*\)?\s*)");   std::smatch m;   if (std::regex_match(s, m, r)) {     return JPH::Vec3(std::stof(m[1]), std::stof(m[2]), std::stof(m[3]));   }   throw std::invalid_argument("Invalid JPH::Vec3 string"); };
                    obj.position = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) {   std::regex r(R"(\s*\(?\s*([-+]?[0-9]*\.?[0-9]+)\s*,\s*([-+]?[0-9]*\.?[0-9]+)\s*,\s*([-+]?[0-9]*\.?[0-9]+)\s*\)?\s*)");   std::smatch m;   if (std::regex_match(s, m, r)) {     return JPH::Vec3(std::stof(m[1]), std::stof(m[2]), std::stof(m[3]));   }   throw std::invalid_argument("Invalid JPH::Vec3 string"); };
                    obj.velocity = conv(value_str);
                }
            }
            return obj;
        };
                    obj.character_physics_state = conv(value_str);
                }
            }
            return obj;
        };
                    obj.id_tagged_character_physics_state = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &s) -> IdTaggedCharacterCameraState {
            IdTaggedCharacterCameraState obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return static_cast<unsigned int>(std::stoul(s)); };
                    obj.id_of_last_update_data_used_to_produce_this_state = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &s) -> CharacterCameraState {
            CharacterCameraState obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return std::stod(s); };
                    obj.yaw = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return std::stod(s); };
                    obj.pitch = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return std::stod(s); };
                    obj.last_mouse_position_x = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return std::stod(s); };
                    obj.last_mouse_position_y = conv(value_str);
                }
            }
            return obj;
        };
                    obj.character_camera_state = conv(value_str);
                }
            }
            return obj;
        };
                    obj.id_tagged_character_camera_state = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &s) -> CharacterPhysicsState {
            CharacterPhysicsState obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) {   std::regex r(R"(\s*\(?\s*([-+]?[0-9]*\.?[0-9]+)\s*,\s*([-+]?[0-9]*\.?[0-9]+)\s*,\s*([-+]?[0-9]*\.?[0-9]+)\s*\)?\s*)");   std::smatch m;   if (std::regex_match(s, m, r)) {     return JPH::Vec3(std::stof(m[1]), std::stof(m[2]), std::stof(m[3]));   }   throw std::invalid_argument("Invalid JPH::Vec3 string"); };
                    obj.position = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) {   std::regex r(R"(\s*\(?\s*([-+]?[0-9]*\.?[0-9]+)\s*,\s*([-+]?[0-9]*\.?[0-9]+)\s*,\s*([-+]?[0-9]*\.?[0-9]+)\s*\)?\s*)");   std::smatch m;   if (std::regex_match(s, m, r)) {     return JPH::Vec3(std::stof(m[1]), std::stof(m[2]), std::stof(m[3]));   }   throw std::invalid_argument("Invalid JPH::Vec3 string"); };
                    obj.velocity = conv(value_str);
                }
            }
            return obj;
        };
                    obj.target_physics_state = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &input) -> std::vector<SoundType> {
            std::string trimmed = input;
            if (!trimmed.empty() && trimmed.front() == '{' && trimmed.back() == '}') {
                trimmed = trimmed.substr(1, trimmed.size() - 2);
            }
        
            std::vector<SoundType> result;
            std::regex element_re(R"(.*)");
            auto begin = std::sregex_iterator(trimmed.begin(), trimmed.end(), element_re);
            auto end = std::sregex_iterator();
        
            for (auto it = begin; it != end; ++it) {
                try {
                    auto conversion = [=](const std::string &s) -> SoundType {
            if (s == "SoundType::UI_HOVER") return SoundType::UI_HOVER;
            if (s == "SoundType::UI_CLICK") return SoundType::UI_CLICK;
            if (s == "SoundType::UI_SUCCESS") return SoundType::UI_SUCCESS;
            if (s == "SoundType::CLIENT_HIT") return SoundType::CLIENT_HIT;
            if (s == "SoundType::CLIENT_MISS") return SoundType::CLIENT_MISS;
            if (s == "SoundType::SERVER_HIT") return SoundType::SERVER_HIT;
            if (s == "SoundType::SERVER_MISS") return SoundType::SERVER_MISS;
            return static_cast<SoundType>(0); // default fallback
        };
                    result.push_back(conversion(it->str()));
                } catch (...) {
                    // Ignore malformed elements
                }
            }
            return result;
        };
                    obj.sounds = conv(value_str);
                }
            }
            return obj;

    }
    std::vector<uint8_t> serialize_GameState(const GameState obj) {
        std::vector<uint8_t> buffer;
            { auto ser = [](const unsigned int &v) {   std::vector<uint8_t> buf(sizeof(unsigned int));   std::memcpy(buf.data(), &v, sizeof(unsigned int));   return buf; };
              auto bytes = ser(obj.id);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [=](const IdTaggedCharacterPhysicsState& obj) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            { auto ser = [](const unsigned int &v) {   std::vector<uint8_t> buf(sizeof(unsigned int));   std::memcpy(buf.data(), &v, sizeof(unsigned int));   return buf; };
              auto bytes = ser(obj.id_of_last_update_data_used_to_produce_this_state);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [=](const CharacterPhysicsState& obj) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            { auto ser = [](const JPH::Vec3 &v) {   std::vector<uint8_t> buf(sizeof(JPH::Vec3));   std::memcpy(buf.data(), &v, sizeof(JPH::Vec3));   return buf; };
              auto bytes = ser(obj.position);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const JPH::Vec3 &v) {   std::vector<uint8_t> buf(sizeof(JPH::Vec3));   std::memcpy(buf.data(), &v, sizeof(JPH::Vec3));   return buf; };
              auto bytes = ser(obj.velocity);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;
        };
              auto bytes = ser(obj.character_physics_state);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;
        };
              auto bytes = ser(obj.id_tagged_character_physics_state);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [=](const IdTaggedCharacterCameraState& obj) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            { auto ser = [](const unsigned int &v) {   std::vector<uint8_t> buf(sizeof(unsigned int));   std::memcpy(buf.data(), &v, sizeof(unsigned int));   return buf; };
              auto bytes = ser(obj.id_of_last_update_data_used_to_produce_this_state);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [=](const CharacterCameraState& obj) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            { auto ser = [](const double &v) {   std::vector<uint8_t> buf(sizeof(double));   std::memcpy(buf.data(), &v, sizeof(double));   return buf; };
              auto bytes = ser(obj.yaw);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const double &v) {   std::vector<uint8_t> buf(sizeof(double));   std::memcpy(buf.data(), &v, sizeof(double));   return buf; };
              auto bytes = ser(obj.pitch);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const double &v) {   std::vector<uint8_t> buf(sizeof(double));   std::memcpy(buf.data(), &v, sizeof(double));   return buf; };
              auto bytes = ser(obj.last_mouse_position_x);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const double &v) {   std::vector<uint8_t> buf(sizeof(double));   std::memcpy(buf.data(), &v, sizeof(double));   return buf; };
              auto bytes = ser(obj.last_mouse_position_y);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;
        };
              auto bytes = ser(obj.character_camera_state);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;
        };
              auto bytes = ser(obj.id_tagged_character_camera_state);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [=](const CharacterPhysicsState& obj) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            { auto ser = [](const JPH::Vec3 &v) {   std::vector<uint8_t> buf(sizeof(JPH::Vec3));   std::memcpy(buf.data(), &v, sizeof(JPH::Vec3));   return buf; };
              auto bytes = ser(obj.position);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const JPH::Vec3 &v) {   std::vector<uint8_t> buf(sizeof(JPH::Vec3));   std::memcpy(buf.data(), &v, sizeof(JPH::Vec3));   return buf; };
              auto bytes = ser(obj.velocity);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;
        };
              auto bytes = ser(obj.target_physics_state);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [=](const std::vector<SoundType>& vec) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            // store vector size first, which is necessary or else we won't know when to stop during deserialization
            size_t count = vec.size();
            buffer.resize(sizeof(size_t));
            std::memcpy(buffer.data(), &count, sizeof(size_t));
        
            auto element_serializer = [=](SoundType value) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer(sizeof(int));
            int raw = static_cast<int>(value);
            std::memcpy(buffer.data(), &raw, sizeof(int));
            return buffer;
        };
            for (const auto& elem : vec) {
                auto elem_bytes = element_serializer(elem);
                buffer.insert(buffer.end(), elem_bytes.begin(), elem_bytes.end());
            }
            return buffer;
        };
              auto bytes = ser(obj.sounds);
              size_t len = bytes.size();
              buffer.resize(buffer.size() + sizeof(size_t));
              std::memcpy(buffer.data() + buffer.size() - sizeof(size_t), &len, sizeof(size_t));
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;

    }
    size_t size_when_serialized_GameState(const GameState obj) {
        size_t total = 0;
            { auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              total += size_fn(obj.id); }
            { auto size_fn = [=](const IdTaggedCharacterPhysicsState& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              total += size_fn(obj.id_of_last_update_data_used_to_produce_this_state); }
            { auto size_fn = [=](const CharacterPhysicsState& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const JPH::Vec3 &v) { return sizeof(JPH::Vec3); };
              total += size_fn(obj.position); }
            { auto size_fn = [](const JPH::Vec3 &v) { return sizeof(JPH::Vec3); };
              total += size_fn(obj.velocity); }
            return total;
        };
              total += size_fn(obj.character_physics_state); }
            return total;
        };
              total += size_fn(obj.id_tagged_character_physics_state); }
            { auto size_fn = [=](const IdTaggedCharacterCameraState& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              total += size_fn(obj.id_of_last_update_data_used_to_produce_this_state); }
            { auto size_fn = [=](const CharacterCameraState& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.yaw); }
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.pitch); }
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.last_mouse_position_x); }
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.last_mouse_position_y); }
            return total;
        };
              total += size_fn(obj.character_camera_state); }
            return total;
        };
              total += size_fn(obj.id_tagged_character_camera_state); }
            { auto size_fn = [=](const CharacterPhysicsState& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const JPH::Vec3 &v) { return sizeof(JPH::Vec3); };
              total += size_fn(obj.position); }
            { auto size_fn = [](const JPH::Vec3 &v) { return sizeof(JPH::Vec3); };
              total += size_fn(obj.velocity); }
            return total;
        };
              total += size_fn(obj.target_physics_state); }
            { auto size_fn = [=](const std::vector<SoundType>& vec) -> size_t {
            size_t total_size = sizeof(size_t); // space for storing count
            if (!vec.empty()) {
                total_size += vec.size() * [=](const SoundType &obj) -> size_t {
            return sizeof(int);
        }(vec[0]);
            }
            return total_size;
        };
              total += sizeof(size_t); // length prefix
              total += size_fn(obj.sounds); }
            return total;

    }
    GameState deserialize_GameState(const std::vector<uint8_t> &buffer) {
        GameState obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   unsigned int v;   std::memcpy(&v, buf.data(), sizeof(unsigned int));   return v; };
              auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              size_t len = size_fn(obj.id);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.id = deser(slice);
              offset += len;
            }
            { auto deser = [=](const std::vector<uint8_t> &buffer) -> IdTaggedCharacterPhysicsState {
            IdTaggedCharacterPhysicsState obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   unsigned int v;   std::memcpy(&v, buf.data(), sizeof(unsigned int));   return v; };
              auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              size_t len = size_fn(obj.id_of_last_update_data_used_to_produce_this_state);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.id_of_last_update_data_used_to_produce_this_state = deser(slice);
              offset += len;
            }
            { auto deser = [=](const std::vector<uint8_t> &buffer) -> CharacterPhysicsState {
            CharacterPhysicsState obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   JPH::Vec3 v;   std::memcpy(&v, buf.data(), sizeof(JPH::Vec3));   return v; };
              auto size_fn = [](const JPH::Vec3 &v) { return sizeof(JPH::Vec3); };
              size_t len = size_fn(obj.position);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.position = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   JPH::Vec3 v;   std::memcpy(&v, buf.data(), sizeof(JPH::Vec3));   return v; };
              auto size_fn = [](const JPH::Vec3 &v) { return sizeof(JPH::Vec3); };
              size_t len = size_fn(obj.velocity);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.velocity = deser(slice);
              offset += len;
            }
            return obj;
        };
              auto size_fn = [=](const CharacterPhysicsState& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const JPH::Vec3 &v) { return sizeof(JPH::Vec3); };
              total += size_fn(obj.position); }
            { auto size_fn = [](const JPH::Vec3 &v) { return sizeof(JPH::Vec3); };
              total += size_fn(obj.velocity); }
            return total;
        };
              size_t len = size_fn(obj.character_physics_state);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.character_physics_state = deser(slice);
              offset += len;
            }
            return obj;
        };
              auto size_fn = [=](const IdTaggedCharacterPhysicsState& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              total += size_fn(obj.id_of_last_update_data_used_to_produce_this_state); }
            { auto size_fn = [=](const CharacterPhysicsState& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const JPH::Vec3 &v) { return sizeof(JPH::Vec3); };
              total += size_fn(obj.position); }
            { auto size_fn = [](const JPH::Vec3 &v) { return sizeof(JPH::Vec3); };
              total += size_fn(obj.velocity); }
            return total;
        };
              total += size_fn(obj.character_physics_state); }
            return total;
        };
              size_t len = size_fn(obj.id_tagged_character_physics_state);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.id_tagged_character_physics_state = deser(slice);
              offset += len;
            }
            { auto deser = [=](const std::vector<uint8_t> &buffer) -> IdTaggedCharacterCameraState {
            IdTaggedCharacterCameraState obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   unsigned int v;   std::memcpy(&v, buf.data(), sizeof(unsigned int));   return v; };
              auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              size_t len = size_fn(obj.id_of_last_update_data_used_to_produce_this_state);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.id_of_last_update_data_used_to_produce_this_state = deser(slice);
              offset += len;
            }
            { auto deser = [=](const std::vector<uint8_t> &buffer) -> CharacterCameraState {
            CharacterCameraState obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   double v;   std::memcpy(&v, buf.data(), sizeof(double));   return v; };
              auto size_fn = [](const double &v) { return sizeof(double); };
              size_t len = size_fn(obj.yaw);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.yaw = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   double v;   std::memcpy(&v, buf.data(), sizeof(double));   return v; };
              auto size_fn = [](const double &v) { return sizeof(double); };
              size_t len = size_fn(obj.pitch);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.pitch = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   double v;   std::memcpy(&v, buf.data(), sizeof(double));   return v; };
              auto size_fn = [](const double &v) { return sizeof(double); };
              size_t len = size_fn(obj.last_mouse_position_x);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.last_mouse_position_x = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   double v;   std::memcpy(&v, buf.data(), sizeof(double));   return v; };
              auto size_fn = [](const double &v) { return sizeof(double); };
              size_t len = size_fn(obj.last_mouse_position_y);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.last_mouse_position_y = deser(slice);
              offset += len;
            }
            return obj;
        };
              auto size_fn = [=](const CharacterCameraState& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.yaw); }
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.pitch); }
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.last_mouse_position_x); }
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.last_mouse_position_y); }
            return total;
        };
              size_t len = size_fn(obj.character_camera_state);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.character_camera_state = deser(slice);
              offset += len;
            }
            return obj;
        };
              auto size_fn = [=](const IdTaggedCharacterCameraState& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              total += size_fn(obj.id_of_last_update_data_used_to_produce_this_state); }
            { auto size_fn = [=](const CharacterCameraState& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.yaw); }
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.pitch); }
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.last_mouse_position_x); }
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.last_mouse_position_y); }
            return total;
        };
              total += size_fn(obj.character_camera_state); }
            return total;
        };
              size_t len = size_fn(obj.id_tagged_character_camera_state);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.id_tagged_character_camera_state = deser(slice);
              offset += len;
            }
            { auto deser = [=](const std::vector<uint8_t> &buffer) -> CharacterPhysicsState {
            CharacterPhysicsState obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   JPH::Vec3 v;   std::memcpy(&v, buf.data(), sizeof(JPH::Vec3));   return v; };
              auto size_fn = [](const JPH::Vec3 &v) { return sizeof(JPH::Vec3); };
              size_t len = size_fn(obj.position);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.position = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   JPH::Vec3 v;   std::memcpy(&v, buf.data(), sizeof(JPH::Vec3));   return v; };
              auto size_fn = [](const JPH::Vec3 &v) { return sizeof(JPH::Vec3); };
              size_t len = size_fn(obj.velocity);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.velocity = deser(slice);
              offset += len;
            }
            return obj;
        };
              auto size_fn = [=](const CharacterPhysicsState& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const JPH::Vec3 &v) { return sizeof(JPH::Vec3); };
              total += size_fn(obj.position); }
            { auto size_fn = [](const JPH::Vec3 &v) { return sizeof(JPH::Vec3); };
              total += size_fn(obj.velocity); }
            return total;
        };
              size_t len = size_fn(obj.target_physics_state);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.target_physics_state = deser(slice);
              offset += len;
            }
            { auto deser = [=](const std::vector<uint8_t>& buffer) -> std::vector<SoundType> {
            std::vector<SoundType> result;
            if (buffer.size() < sizeof(size_t)) return result;
            size_t count;
            std::memcpy(&count, buffer.data(), sizeof(size_t));
        
            size_t offset = sizeof(size_t);
            auto element_deserializer = [=](const std::vector<uint8_t> &buffer) -> SoundType {
            if (buffer.size() < sizeof(int)) return static_cast<SoundType>(0);
            int raw = 0;
            std::memcpy(&raw, buffer.data(), sizeof(int));
            return static_cast<SoundType>(raw);
        };
            // NOTE: big assumption, assumes the default constructor exists for this object. There's gotta be a better way, what if we made size when serialized take in an optional value.
            SoundType dummy; 
            auto size_fn = [=](const SoundType &obj) -> size_t {
            return sizeof(int);
        };
            size_t elem_size = size_fn(dummy);
            if (offset + count * elem_size > buffer.size()) return result; // safety check
            for (size_t i = 0; i < count; ++i) {
                std::vector<uint8_t> elem_buf(buffer.begin() + offset, buffer.begin() + offset + elem_size);
                SoundType elem = element_deserializer(elem_buf);
                result.push_back(elem);
                offset += elem_size;
            }
            return result;
        };
              if (offset + sizeof(size_t) > buffer.size()) return obj;
              size_t len = 0;
              std::memcpy(&len, buffer.data() + offset, sizeof(size_t));
              offset += sizeof(size_t);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.sounds = deser(slice);
              offset += len;
            }
            return obj;

    }
    std::string GameStatePacket_to_string(const GameStatePacket obj) {
        std::ostringstream oss;
            oss << "{";
            { auto conv = [=](const PacketHeader& obj) -> std::string {
            std::ostringstream oss;
            oss << "{";
            { auto conv = [=](PacketType value) -> std::string {
            switch(value) {
                case PacketType::CLIENT_UPDATE_DATA: return "PacketType::CLIENT_UPDATE_DATA";
                case PacketType::GAME_STATE: return "PacketType::GAME_STATE";
                case PacketType::NUM_ENUMERATORS: return "PacketType::NUM_ENUMERATORS";
                default: return "<unknown PacketType>";
            }
        };
              oss << "type=" << conv(obj.type); }
            oss << ", ";
            { auto conv = [](const uint32_t &v) { return std::to_string(v); };
              oss << "size_of_data_without_header=" << conv(obj.size_of_data_without_header); }
            oss << "}";
            return oss.str();
        };
              oss << "packet_header=" << conv(obj.packet_header); }
            oss << ", ";
            { auto conv = [=](const GameState& obj) -> std::string {
            std::ostringstream oss;
            oss << "{";
            { auto conv = [](const unsigned int &v) { return std::to_string(v); };
              oss << "id=" << conv(obj.id); }
            oss << ", ";
            { auto conv = [=](const IdTaggedCharacterPhysicsState& obj) -> std::string {
            std::ostringstream oss;
            oss << "{";
            { auto conv = [](const unsigned int &v) { return std::to_string(v); };
              oss << "id_of_last_update_data_used_to_produce_this_state=" << conv(obj.id_of_last_update_data_used_to_produce_this_state); }
            oss << ", ";
            { auto conv = [=](const CharacterPhysicsState& obj) -> std::string {
            std::ostringstream oss;
            oss << "{";
            { auto conv = [](const JPH::Vec3 &v) {   std::ostringstream oss;   oss << std::setprecision(std::numeric_limits<float>::max_digits10) << std::fixed;   oss << '(' << v.GetX() << ", " << v.GetY() << ", " << v.GetZ() << ')';   return oss.str(); };
              oss << "position=" << conv(obj.position); }
            oss << ", ";
            { auto conv = [](const JPH::Vec3 &v) {   std::ostringstream oss;   oss << std::setprecision(std::numeric_limits<float>::max_digits10) << std::fixed;   oss << '(' << v.GetX() << ", " << v.GetY() << ", " << v.GetZ() << ')';   return oss.str(); };
              oss << "velocity=" << conv(obj.velocity); }
            oss << "}";
            return oss.str();
        };
              oss << "character_physics_state=" << conv(obj.character_physics_state); }
            oss << "}";
            return oss.str();
        };
              oss << "id_tagged_character_physics_state=" << conv(obj.id_tagged_character_physics_state); }
            oss << ", ";
            { auto conv = [=](const IdTaggedCharacterCameraState& obj) -> std::string {
            std::ostringstream oss;
            oss << "{";
            { auto conv = [](const unsigned int &v) { return std::to_string(v); };
              oss << "id_of_last_update_data_used_to_produce_this_state=" << conv(obj.id_of_last_update_data_used_to_produce_this_state); }
            oss << ", ";
            { auto conv = [=](const CharacterCameraState& obj) -> std::string {
            std::ostringstream oss;
            oss << "{";
            { auto conv = [](const double &v) {  std::ostringstream oss;  oss << std::setprecision(std::numeric_limits<double>::max_digits10) << v;  return oss.str();};
              oss << "yaw=" << conv(obj.yaw); }
            oss << ", ";
            { auto conv = [](const double &v) {  std::ostringstream oss;  oss << std::setprecision(std::numeric_limits<double>::max_digits10) << v;  return oss.str();};
              oss << "pitch=" << conv(obj.pitch); }
            oss << ", ";
            { auto conv = [](const double &v) {  std::ostringstream oss;  oss << std::setprecision(std::numeric_limits<double>::max_digits10) << v;  return oss.str();};
              oss << "last_mouse_position_x=" << conv(obj.last_mouse_position_x); }
            oss << ", ";
            { auto conv = [](const double &v) {  std::ostringstream oss;  oss << std::setprecision(std::numeric_limits<double>::max_digits10) << v;  return oss.str();};
              oss << "last_mouse_position_y=" << conv(obj.last_mouse_position_y); }
            oss << "}";
            return oss.str();
        };
              oss << "character_camera_state=" << conv(obj.character_camera_state); }
            oss << "}";
            return oss.str();
        };
              oss << "id_tagged_character_camera_state=" << conv(obj.id_tagged_character_camera_state); }
            oss << ", ";
            { auto conv = [=](const CharacterPhysicsState& obj) -> std::string {
            std::ostringstream oss;
            oss << "{";
            { auto conv = [](const JPH::Vec3 &v) {   std::ostringstream oss;   oss << std::setprecision(std::numeric_limits<float>::max_digits10) << std::fixed;   oss << '(' << v.GetX() << ", " << v.GetY() << ", " << v.GetZ() << ')';   return oss.str(); };
              oss << "position=" << conv(obj.position); }
            oss << ", ";
            { auto conv = [](const JPH::Vec3 &v) {   std::ostringstream oss;   oss << std::setprecision(std::numeric_limits<float>::max_digits10) << std::fixed;   oss << '(' << v.GetX() << ", " << v.GetY() << ", " << v.GetZ() << ')';   return oss.str(); };
              oss << "velocity=" << conv(obj.velocity); }
            oss << "}";
            return oss.str();
        };
              oss << "target_physics_state=" << conv(obj.target_physics_state); }
            oss << ", ";
            { auto conv = [=](const std::vector<SoundType>& vec) -> std::string {
            std::ostringstream oss;
            oss << "{";
            auto conversion = [=](SoundType value) -> std::string {
            switch(value) {
                case SoundType::UI_HOVER: return "SoundType::UI_HOVER";
                case SoundType::UI_CLICK: return "SoundType::UI_CLICK";
                case SoundType::UI_SUCCESS: return "SoundType::UI_SUCCESS";
                case SoundType::CLIENT_HIT: return "SoundType::CLIENT_HIT";
                case SoundType::CLIENT_MISS: return "SoundType::CLIENT_MISS";
                case SoundType::SERVER_HIT: return "SoundType::SERVER_HIT";
                case SoundType::SERVER_MISS: return "SoundType::SERVER_MISS";
                default: return "<unknown SoundType>";
            }
        };
        
            for (size_t i = 0; i < vec.size(); ++i) {
                oss << conversion(vec[i]);
                if (i + 1 < vec.size())
                    oss << ", ";
            }
        
            oss << "}";
            return oss.str();
        };
              oss << "sounds=" << conv(obj.sounds); }
            oss << "}";
            return oss.str();
        };
              oss << "game_state=" << conv(obj.game_state); }
            oss << "}";
            return oss.str();

    }
    GameStatePacket string_to_GameStatePacket(const std::string &s) {
        GameStatePacket obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &s) -> PacketHeader {
            PacketHeader obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &s) -> PacketType {
            if (s == "PacketType::CLIENT_UPDATE_DATA") return PacketType::CLIENT_UPDATE_DATA;
            if (s == "PacketType::GAME_STATE") return PacketType::GAME_STATE;
            if (s == "PacketType::NUM_ENUMERATORS") return PacketType::NUM_ENUMERATORS;
            return static_cast<PacketType>(0); // default fallback
        };
                    obj.type = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return static_cast<uint32_t>(std::stoul(s)); };
                    obj.size_of_data_without_header = conv(value_str);
                }
            }
            return obj;
        };
                    obj.packet_header = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &s) -> GameState {
            GameState obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return static_cast<unsigned int>(std::stoul(s)); };
                    obj.id = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &s) -> IdTaggedCharacterPhysicsState {
            IdTaggedCharacterPhysicsState obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return static_cast<unsigned int>(std::stoul(s)); };
                    obj.id_of_last_update_data_used_to_produce_this_state = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &s) -> CharacterPhysicsState {
            CharacterPhysicsState obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) {   std::regex r(R"(\s*\(?\s*([-+]?[0-9]*\.?[0-9]+)\s*,\s*([-+]?[0-9]*\.?[0-9]+)\s*,\s*([-+]?[0-9]*\.?[0-9]+)\s*\)?\s*)");   std::smatch m;   if (std::regex_match(s, m, r)) {     return JPH::Vec3(std::stof(m[1]), std::stof(m[2]), std::stof(m[3]));   }   throw std::invalid_argument("Invalid JPH::Vec3 string"); };
                    obj.position = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) {   std::regex r(R"(\s*\(?\s*([-+]?[0-9]*\.?[0-9]+)\s*,\s*([-+]?[0-9]*\.?[0-9]+)\s*,\s*([-+]?[0-9]*\.?[0-9]+)\s*\)?\s*)");   std::smatch m;   if (std::regex_match(s, m, r)) {     return JPH::Vec3(std::stof(m[1]), std::stof(m[2]), std::stof(m[3]));   }   throw std::invalid_argument("Invalid JPH::Vec3 string"); };
                    obj.velocity = conv(value_str);
                }
            }
            return obj;
        };
                    obj.character_physics_state = conv(value_str);
                }
            }
            return obj;
        };
                    obj.id_tagged_character_physics_state = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &s) -> IdTaggedCharacterCameraState {
            IdTaggedCharacterCameraState obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return static_cast<unsigned int>(std::stoul(s)); };
                    obj.id_of_last_update_data_used_to_produce_this_state = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &s) -> CharacterCameraState {
            CharacterCameraState obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return std::stod(s); };
                    obj.yaw = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return std::stod(s); };
                    obj.pitch = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return std::stod(s); };
                    obj.last_mouse_position_x = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) { return std::stod(s); };
                    obj.last_mouse_position_y = conv(value_str);
                }
            }
            return obj;
        };
                    obj.character_camera_state = conv(value_str);
                }
            }
            return obj;
        };
                    obj.id_tagged_character_camera_state = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &s) -> CharacterPhysicsState {
            CharacterPhysicsState obj;
            std::string trimmed = s.substr(1, s.size() - 2); // remove {}
            std::istringstream iss(trimmed);
            std::string token;
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) {   std::regex r(R"(\s*\(?\s*([-+]?[0-9]*\.?[0-9]+)\s*,\s*([-+]?[0-9]*\.?[0-9]+)\s*,\s*([-+]?[0-9]*\.?[0-9]+)\s*\)?\s*)");   std::smatch m;   if (std::regex_match(s, m, r)) {     return JPH::Vec3(std::stof(m[1]), std::stof(m[2]), std::stof(m[3]));   }   throw std::invalid_argument("Invalid JPH::Vec3 string"); };
                    obj.position = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [](const std::string &s) {   std::regex r(R"(\s*\(?\s*([-+]?[0-9]*\.?[0-9]+)\s*,\s*([-+]?[0-9]*\.?[0-9]+)\s*,\s*([-+]?[0-9]*\.?[0-9]+)\s*\)?\s*)");   std::smatch m;   if (std::regex_match(s, m, r)) {     return JPH::Vec3(std::stof(m[1]), std::stof(m[2]), std::stof(m[3]));   }   throw std::invalid_argument("Invalid JPH::Vec3 string"); };
                    obj.velocity = conv(value_str);
                }
            }
            return obj;
        };
                    obj.target_physics_state = conv(value_str);
                }
            }
            if (std::getline(iss, token, ',')) {
                auto pos = token.find('=');
                if (pos != std::string::npos) {
                    std::string value_str = token.substr(pos + 1);
                    auto conv = [=](const std::string &input) -> std::vector<SoundType> {
            std::string trimmed = input;
            if (!trimmed.empty() && trimmed.front() == '{' && trimmed.back() == '}') {
                trimmed = trimmed.substr(1, trimmed.size() - 2);
            }
        
            std::vector<SoundType> result;
            std::regex element_re(R"(.*)");
            auto begin = std::sregex_iterator(trimmed.begin(), trimmed.end(), element_re);
            auto end = std::sregex_iterator();
        
            for (auto it = begin; it != end; ++it) {
                try {
                    auto conversion = [=](const std::string &s) -> SoundType {
            if (s == "SoundType::UI_HOVER") return SoundType::UI_HOVER;
            if (s == "SoundType::UI_CLICK") return SoundType::UI_CLICK;
            if (s == "SoundType::UI_SUCCESS") return SoundType::UI_SUCCESS;
            if (s == "SoundType::CLIENT_HIT") return SoundType::CLIENT_HIT;
            if (s == "SoundType::CLIENT_MISS") return SoundType::CLIENT_MISS;
            if (s == "SoundType::SERVER_HIT") return SoundType::SERVER_HIT;
            if (s == "SoundType::SERVER_MISS") return SoundType::SERVER_MISS;
            return static_cast<SoundType>(0); // default fallback
        };
                    result.push_back(conversion(it->str()));
                } catch (...) {
                    // Ignore malformed elements
                }
            }
            return result;
        };
                    obj.sounds = conv(value_str);
                }
            }
            return obj;
        };
                    obj.game_state = conv(value_str);
                }
            }
            return obj;

    }
    std::vector<uint8_t> serialize_GameStatePacket(const GameStatePacket obj) {
        std::vector<uint8_t> buffer;
            { auto ser = [=](const PacketHeader& obj) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            { auto ser = [=](PacketType value) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer(sizeof(uint8_t));
            uint8_t raw = static_cast<uint8_t>(value);
            std::memcpy(buffer.data(), &raw, sizeof(uint8_t));
            return buffer;
        };
              auto bytes = ser(obj.type);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const uint32_t &v) {   std::vector<uint8_t> buf(sizeof(uint32_t));   std::memcpy(buf.data(), &v, sizeof(uint32_t));   return buf; };
              auto bytes = ser(obj.size_of_data_without_header);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;
        };
              auto bytes = ser(obj.packet_header);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [=](const GameState& obj) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            { auto ser = [](const unsigned int &v) {   std::vector<uint8_t> buf(sizeof(unsigned int));   std::memcpy(buf.data(), &v, sizeof(unsigned int));   return buf; };
              auto bytes = ser(obj.id);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [=](const IdTaggedCharacterPhysicsState& obj) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            { auto ser = [](const unsigned int &v) {   std::vector<uint8_t> buf(sizeof(unsigned int));   std::memcpy(buf.data(), &v, sizeof(unsigned int));   return buf; };
              auto bytes = ser(obj.id_of_last_update_data_used_to_produce_this_state);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [=](const CharacterPhysicsState& obj) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            { auto ser = [](const JPH::Vec3 &v) {   std::vector<uint8_t> buf(sizeof(JPH::Vec3));   std::memcpy(buf.data(), &v, sizeof(JPH::Vec3));   return buf; };
              auto bytes = ser(obj.position);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const JPH::Vec3 &v) {   std::vector<uint8_t> buf(sizeof(JPH::Vec3));   std::memcpy(buf.data(), &v, sizeof(JPH::Vec3));   return buf; };
              auto bytes = ser(obj.velocity);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;
        };
              auto bytes = ser(obj.character_physics_state);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;
        };
              auto bytes = ser(obj.id_tagged_character_physics_state);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [=](const IdTaggedCharacterCameraState& obj) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            { auto ser = [](const unsigned int &v) {   std::vector<uint8_t> buf(sizeof(unsigned int));   std::memcpy(buf.data(), &v, sizeof(unsigned int));   return buf; };
              auto bytes = ser(obj.id_of_last_update_data_used_to_produce_this_state);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [=](const CharacterCameraState& obj) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            { auto ser = [](const double &v) {   std::vector<uint8_t> buf(sizeof(double));   std::memcpy(buf.data(), &v, sizeof(double));   return buf; };
              auto bytes = ser(obj.yaw);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const double &v) {   std::vector<uint8_t> buf(sizeof(double));   std::memcpy(buf.data(), &v, sizeof(double));   return buf; };
              auto bytes = ser(obj.pitch);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const double &v) {   std::vector<uint8_t> buf(sizeof(double));   std::memcpy(buf.data(), &v, sizeof(double));   return buf; };
              auto bytes = ser(obj.last_mouse_position_x);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const double &v) {   std::vector<uint8_t> buf(sizeof(double));   std::memcpy(buf.data(), &v, sizeof(double));   return buf; };
              auto bytes = ser(obj.last_mouse_position_y);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;
        };
              auto bytes = ser(obj.character_camera_state);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;
        };
              auto bytes = ser(obj.id_tagged_character_camera_state);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [=](const CharacterPhysicsState& obj) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            { auto ser = [](const JPH::Vec3 &v) {   std::vector<uint8_t> buf(sizeof(JPH::Vec3));   std::memcpy(buf.data(), &v, sizeof(JPH::Vec3));   return buf; };
              auto bytes = ser(obj.position);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [](const JPH::Vec3 &v) {   std::vector<uint8_t> buf(sizeof(JPH::Vec3));   std::memcpy(buf.data(), &v, sizeof(JPH::Vec3));   return buf; };
              auto bytes = ser(obj.velocity);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;
        };
              auto bytes = ser(obj.target_physics_state);
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            { auto ser = [=](const std::vector<SoundType>& vec) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer;
            // store vector size first, which is necessary or else we won't know when to stop during deserialization
            size_t count = vec.size();
            buffer.resize(sizeof(size_t));
            std::memcpy(buffer.data(), &count, sizeof(size_t));
        
            auto element_serializer = [=](SoundType value) -> std::vector<uint8_t> {
            std::vector<uint8_t> buffer(sizeof(int));
            int raw = static_cast<int>(value);
            std::memcpy(buffer.data(), &raw, sizeof(int));
            return buffer;
        };
            for (const auto& elem : vec) {
                auto elem_bytes = element_serializer(elem);
                buffer.insert(buffer.end(), elem_bytes.begin(), elem_bytes.end());
            }
            return buffer;
        };
              auto bytes = ser(obj.sounds);
              size_t len = bytes.size();
              buffer.resize(buffer.size() + sizeof(size_t));
              std::memcpy(buffer.data() + buffer.size() - sizeof(size_t), &len, sizeof(size_t));
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;
        };
              auto bytes = ser(obj.game_state);
              size_t len = bytes.size();
              buffer.resize(buffer.size() + sizeof(size_t));
              std::memcpy(buffer.data() + buffer.size() - sizeof(size_t), &len, sizeof(size_t));
              buffer.insert(buffer.end(), bytes.begin(), bytes.end()); }
            return buffer;

    }
    size_t size_when_serialized_GameStatePacket(const GameStatePacket obj) {
        size_t total = 0;
            { auto size_fn = [=](const PacketHeader& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [=](const PacketType &obj) -> size_t {
            return sizeof(uint8_t);
        };
              total += size_fn(obj.type); }
            { auto size_fn = [](const uint32_t &v) { return sizeof(uint32_t); };
              total += size_fn(obj.size_of_data_without_header); }
            return total;
        };
              total += size_fn(obj.packet_header); }
            { auto size_fn = [=](const GameState& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              total += size_fn(obj.id); }
            { auto size_fn = [=](const IdTaggedCharacterPhysicsState& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              total += size_fn(obj.id_of_last_update_data_used_to_produce_this_state); }
            { auto size_fn = [=](const CharacterPhysicsState& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const JPH::Vec3 &v) { return sizeof(JPH::Vec3); };
              total += size_fn(obj.position); }
            { auto size_fn = [](const JPH::Vec3 &v) { return sizeof(JPH::Vec3); };
              total += size_fn(obj.velocity); }
            return total;
        };
              total += size_fn(obj.character_physics_state); }
            return total;
        };
              total += size_fn(obj.id_tagged_character_physics_state); }
            { auto size_fn = [=](const IdTaggedCharacterCameraState& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              total += size_fn(obj.id_of_last_update_data_used_to_produce_this_state); }
            { auto size_fn = [=](const CharacterCameraState& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.yaw); }
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.pitch); }
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.last_mouse_position_x); }
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.last_mouse_position_y); }
            return total;
        };
              total += size_fn(obj.character_camera_state); }
            return total;
        };
              total += size_fn(obj.id_tagged_character_camera_state); }
            { auto size_fn = [=](const CharacterPhysicsState& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const JPH::Vec3 &v) { return sizeof(JPH::Vec3); };
              total += size_fn(obj.position); }
            { auto size_fn = [](const JPH::Vec3 &v) { return sizeof(JPH::Vec3); };
              total += size_fn(obj.velocity); }
            return total;
        };
              total += size_fn(obj.target_physics_state); }
            { auto size_fn = [=](const std::vector<SoundType>& vec) -> size_t {
            size_t total_size = sizeof(size_t); // space for storing count
            if (!vec.empty()) {
                total_size += vec.size() * [=](const SoundType &obj) -> size_t {
            return sizeof(int);
        }(vec[0]);
            }
            return total_size;
        };
              total += sizeof(size_t); // length prefix
              total += size_fn(obj.sounds); }
            return total;
        };
              total += sizeof(size_t); // length prefix
              total += size_fn(obj.game_state); }
            return total;

    }
    GameStatePacket deserialize_GameStatePacket(const std::vector<uint8_t> &buffer) {
        GameStatePacket obj;
            size_t offset = 0;
            { auto deser = [=](const std::vector<uint8_t> &buffer) -> PacketHeader {
            PacketHeader obj;
            size_t offset = 0;
            { auto deser = [=](const std::vector<uint8_t> &buffer) -> PacketType {
            if (buffer.size() < sizeof(uint8_t)) return static_cast<PacketType>(0);
            uint8_t raw = 0;
            std::memcpy(&raw, buffer.data(), sizeof(uint8_t));
            return static_cast<PacketType>(raw);
        };
              auto size_fn = [=](const PacketType &obj) -> size_t {
            return sizeof(uint8_t);
        };
              size_t len = size_fn(obj.type);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.type = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   uint32_t v;   std::memcpy(&v, buf.data(), sizeof(uint32_t));   return v; };
              auto size_fn = [](const uint32_t &v) { return sizeof(uint32_t); };
              size_t len = size_fn(obj.size_of_data_without_header);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.size_of_data_without_header = deser(slice);
              offset += len;
            }
            return obj;
        };
              auto size_fn = [=](const PacketHeader& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [=](const PacketType &obj) -> size_t {
            return sizeof(uint8_t);
        };
              total += size_fn(obj.type); }
            { auto size_fn = [](const uint32_t &v) { return sizeof(uint32_t); };
              total += size_fn(obj.size_of_data_without_header); }
            return total;
        };
              size_t len = size_fn(obj.packet_header);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.packet_header = deser(slice);
              offset += len;
            }
            { auto deser = [=](const std::vector<uint8_t> &buffer) -> GameState {
            GameState obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   unsigned int v;   std::memcpy(&v, buf.data(), sizeof(unsigned int));   return v; };
              auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              size_t len = size_fn(obj.id);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.id = deser(slice);
              offset += len;
            }
            { auto deser = [=](const std::vector<uint8_t> &buffer) -> IdTaggedCharacterPhysicsState {
            IdTaggedCharacterPhysicsState obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   unsigned int v;   std::memcpy(&v, buf.data(), sizeof(unsigned int));   return v; };
              auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              size_t len = size_fn(obj.id_of_last_update_data_used_to_produce_this_state);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.id_of_last_update_data_used_to_produce_this_state = deser(slice);
              offset += len;
            }
            { auto deser = [=](const std::vector<uint8_t> &buffer) -> CharacterPhysicsState {
            CharacterPhysicsState obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   JPH::Vec3 v;   std::memcpy(&v, buf.data(), sizeof(JPH::Vec3));   return v; };
              auto size_fn = [](const JPH::Vec3 &v) { return sizeof(JPH::Vec3); };
              size_t len = size_fn(obj.position);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.position = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   JPH::Vec3 v;   std::memcpy(&v, buf.data(), sizeof(JPH::Vec3));   return v; };
              auto size_fn = [](const JPH::Vec3 &v) { return sizeof(JPH::Vec3); };
              size_t len = size_fn(obj.velocity);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.velocity = deser(slice);
              offset += len;
            }
            return obj;
        };
              auto size_fn = [=](const CharacterPhysicsState& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const JPH::Vec3 &v) { return sizeof(JPH::Vec3); };
              total += size_fn(obj.position); }
            { auto size_fn = [](const JPH::Vec3 &v) { return sizeof(JPH::Vec3); };
              total += size_fn(obj.velocity); }
            return total;
        };
              size_t len = size_fn(obj.character_physics_state);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.character_physics_state = deser(slice);
              offset += len;
            }
            return obj;
        };
              auto size_fn = [=](const IdTaggedCharacterPhysicsState& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              total += size_fn(obj.id_of_last_update_data_used_to_produce_this_state); }
            { auto size_fn = [=](const CharacterPhysicsState& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const JPH::Vec3 &v) { return sizeof(JPH::Vec3); };
              total += size_fn(obj.position); }
            { auto size_fn = [](const JPH::Vec3 &v) { return sizeof(JPH::Vec3); };
              total += size_fn(obj.velocity); }
            return total;
        };
              total += size_fn(obj.character_physics_state); }
            return total;
        };
              size_t len = size_fn(obj.id_tagged_character_physics_state);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.id_tagged_character_physics_state = deser(slice);
              offset += len;
            }
            { auto deser = [=](const std::vector<uint8_t> &buffer) -> IdTaggedCharacterCameraState {
            IdTaggedCharacterCameraState obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   unsigned int v;   std::memcpy(&v, buf.data(), sizeof(unsigned int));   return v; };
              auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              size_t len = size_fn(obj.id_of_last_update_data_used_to_produce_this_state);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.id_of_last_update_data_used_to_produce_this_state = deser(slice);
              offset += len;
            }
            { auto deser = [=](const std::vector<uint8_t> &buffer) -> CharacterCameraState {
            CharacterCameraState obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   double v;   std::memcpy(&v, buf.data(), sizeof(double));   return v; };
              auto size_fn = [](const double &v) { return sizeof(double); };
              size_t len = size_fn(obj.yaw);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.yaw = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   double v;   std::memcpy(&v, buf.data(), sizeof(double));   return v; };
              auto size_fn = [](const double &v) { return sizeof(double); };
              size_t len = size_fn(obj.pitch);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.pitch = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   double v;   std::memcpy(&v, buf.data(), sizeof(double));   return v; };
              auto size_fn = [](const double &v) { return sizeof(double); };
              size_t len = size_fn(obj.last_mouse_position_x);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.last_mouse_position_x = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   double v;   std::memcpy(&v, buf.data(), sizeof(double));   return v; };
              auto size_fn = [](const double &v) { return sizeof(double); };
              size_t len = size_fn(obj.last_mouse_position_y);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.last_mouse_position_y = deser(slice);
              offset += len;
            }
            return obj;
        };
              auto size_fn = [=](const CharacterCameraState& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.yaw); }
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.pitch); }
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.last_mouse_position_x); }
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.last_mouse_position_y); }
            return total;
        };
              size_t len = size_fn(obj.character_camera_state);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.character_camera_state = deser(slice);
              offset += len;
            }
            return obj;
        };
              auto size_fn = [=](const IdTaggedCharacterCameraState& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const unsigned int &v) { return sizeof(unsigned int); };
              total += size_fn(obj.id_of_last_update_data_used_to_produce_this_state); }
            { auto size_fn = [=](const CharacterCameraState& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.yaw); }
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.pitch); }
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.last_mouse_position_x); }
            { auto size_fn = [](const double &v) { return sizeof(double); };
              total += size_fn(obj.last_mouse_position_y); }
            return total;
        };
              total += size_fn(obj.character_camera_state); }
            return total;
        };
              size_t len = size_fn(obj.id_tagged_character_camera_state);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.id_tagged_character_camera_state = deser(slice);
              offset += len;
            }
            { auto deser = [=](const std::vector<uint8_t> &buffer) -> CharacterPhysicsState {
            CharacterPhysicsState obj;
            size_t offset = 0;
            { auto deser = [](const std::vector<uint8_t> &buf) {   JPH::Vec3 v;   std::memcpy(&v, buf.data(), sizeof(JPH::Vec3));   return v; };
              auto size_fn = [](const JPH::Vec3 &v) { return sizeof(JPH::Vec3); };
              size_t len = size_fn(obj.position);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.position = deser(slice);
              offset += len;
            }
            { auto deser = [](const std::vector<uint8_t> &buf) {   JPH::Vec3 v;   std::memcpy(&v, buf.data(), sizeof(JPH::Vec3));   return v; };
              auto size_fn = [](const JPH::Vec3 &v) { return sizeof(JPH::Vec3); };
              size_t len = size_fn(obj.velocity);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.velocity = deser(slice);
              offset += len;
            }
            return obj;
        };
              auto size_fn = [=](const CharacterPhysicsState& obj) -> size_t {
            size_t total = 0;
            { auto size_fn = [](const JPH::Vec3 &v) { return sizeof(JPH::Vec3); };
              total += size_fn(obj.position); }
            { auto size_fn = [](const JPH::Vec3 &v) { return sizeof(JPH::Vec3); };
              total += size_fn(obj.velocity); }
            return total;
        };
              size_t len = size_fn(obj.target_physics_state);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.target_physics_state = deser(slice);
              offset += len;
            }
            { auto deser = [=](const std::vector<uint8_t>& buffer) -> std::vector<SoundType> {
            std::vector<SoundType> result;
            if (buffer.size() < sizeof(size_t)) return result;
            size_t count;
            std::memcpy(&count, buffer.data(), sizeof(size_t));
        
            size_t offset = sizeof(size_t);
            auto element_deserializer = [=](const std::vector<uint8_t> &buffer) -> SoundType {
            if (buffer.size() < sizeof(int)) return static_cast<SoundType>(0);
            int raw = 0;
            std::memcpy(&raw, buffer.data(), sizeof(int));
            return static_cast<SoundType>(raw);
        };
            // NOTE: big assumption, assumes the default constructor exists for this object. There's gotta be a better way, what if we made size when serialized take in an optional value.
            SoundType dummy; 
            auto size_fn = [=](const SoundType &obj) -> size_t {
            return sizeof(int);
        };
            size_t elem_size = size_fn(dummy);
            if (offset + count * elem_size > buffer.size()) return result; // safety check
            for (size_t i = 0; i < count; ++i) {
                std::vector<uint8_t> elem_buf(buffer.begin() + offset, buffer.begin() + offset + elem_size);
                SoundType elem = element_deserializer(elem_buf);
                result.push_back(elem);
                offset += elem_size;
            }
            return result;
        };
              if (offset + sizeof(size_t) > buffer.size()) return obj;
              size_t len = 0;
              std::memcpy(&len, buffer.data() + offset, sizeof(size_t));
              offset += sizeof(size_t);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.sounds = deser(slice);
              offset += len;
            }
            return obj;
        };
              if (offset + sizeof(size_t) > buffer.size()) return obj;
              size_t len = 0;
              std::memcpy(&len, buffer.data() + offset, sizeof(size_t));
              offset += sizeof(size_t);
              if (offset + len > buffer.size()) return obj;
              std::vector<uint8_t> slice(buffer.begin() + offset, buffer.begin() + offset + len);
              obj.game_state = deser(slice);
              offset += len;
            }
            return obj;

    }
    void list_all_available_functions() {

    }
};


extern LazyConstruction<MetaProgram, std::vector<meta_utils::MetaType>> meta_program;

#endif // META_PROGRAM_HPP
