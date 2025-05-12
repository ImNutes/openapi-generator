#pragma once

#include <nlohmann/json.hpp>
#include <string>
#include <vector>
#include <map>
#include <optional>

struct User {
    std::optional<long> id;
    std::optional<std::string> username;
    std::optional<std::string> firstName;
    std::optional<std::string> lastName;
    std::optional<std::string> email;
    std::optional<std::string> password;
    std::optional<std::string> phone;
    std::optional<int> userStatus;
};

//nlohmann gaming
inline void to_json(nlohmann::json &j, const User &o) {
            if(o.id.has_value()) j[ "id" ] = o.id.value();
            if(o.username.has_value()) j[ "username" ] = o.username.value();
            if(o.firstName.has_value()) j[ "firstName" ] = o.firstName.value();
            if(o.lastName.has_value()) j[ "lastName" ] = o.lastName.value();
            if(o.email.has_value()) j[ "email" ] = o.email.value();
            if(o.password.has_value()) j[ "password" ] = o.password.value();
            if(o.phone.has_value()) j[ "phone" ] = o.phone.value();
            if(o.userStatus.has_value()) j[ "userStatus" ] = o.userStatus.value();
}

inline void from_json(const nlohmann::json &j, const User &o) {
            if(j.contains("id")) j.at("id").get_to(o.id);
            if(j.contains("username")) j.at("username").get_to(o.username);
            if(j.contains("firstName")) j.at("firstName").get_to(o.firstName);
            if(j.contains("lastName")) j.at("lastName").get_to(o.lastName);
            if(j.contains("email")) j.at("email").get_to(o.email);
            if(j.contains("password")) j.at("password").get_to(o.password);
            if(j.contains("phone")) j.at("phone").get_to(o.phone);
            if(j.contains("userStatus")) j.at("userStatus").get_to(o.userStatus);
}

