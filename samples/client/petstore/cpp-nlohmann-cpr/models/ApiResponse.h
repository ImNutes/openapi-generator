#pragma once

#include <nlohmann/json.hpp>
#include <string>
#include <vector>
#include <map>
#include <optional>

struct ApiResponse {
    std::optional<int> code;
    std::optional<std::string> type;
    std::optional<std::string> message;
};

//nlohmann gaming
inline void to_json(nlohmann::json &j, const ApiResponse &o) {
            if(o.code.has_value()) j[ "code" ] = o.code.value();
            if(o.type.has_value()) j[ "type" ] = o.type.value();
            if(o.message.has_value()) j[ "message" ] = o.message.value();
}

inline void from_json(const nlohmann::json &j, const ApiResponse &o) {
            if(j.contains("code")) j.at("code").get_to(o.code);
            if(j.contains("type")) j.at("type").get_to(o.type);
            if(j.contains("message")) j.at("message").get_to(o.message);
}

