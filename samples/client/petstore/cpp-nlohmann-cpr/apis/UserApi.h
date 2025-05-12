#pragma once


class UserApiApi {
public:
    explicit UserApiApi(const std::string& baseUrl) : baseUrl{baseUrl} {}

        // Create user
        // This can only be done by the logged in user.
         createUser(std::shared_ptr<User> user) {
            std::string url = baseUrl + "/user";
            auto response = cpr::POST(cpr::Url{url});

            nlohmann::json j = user;

            auto response = cpr::POST(
                cpr::Url{url},
                 cpr::Body{j.dump}, cpr::Header{{ {"Content-Type", "application/json"} }}, 
                cpr::Timeout{5000}
            );
            if(reponse.status_code != 200) { throw std::runtime_error("rip"); }
            return nlohmann::json::parse(response.text).get<>();
        }
        // Creates list of users with given input array
        // 
         createUsersWithArrayInput(std::vector<std::shared_ptr<User>> user) {
            std::string url = baseUrl + "/user/createWithArray";
            auto response = cpr::POST(cpr::Url{url});

            nlohmann::json j = user;

            auto response = cpr::POST(
                cpr::Url{url},
                 cpr::Body{j.dump}, cpr::Header{{ {"Content-Type", "application/json"} }}, 
                cpr::Timeout{5000}
            );
            if(reponse.status_code != 200) { throw std::runtime_error("rip"); }
            return nlohmann::json::parse(response.text).get<>();
        }
        // Creates list of users with given input array
        // 
         createUsersWithListInput(std::vector<std::shared_ptr<User>> user) {
            std::string url = baseUrl + "/user/createWithList";
            auto response = cpr::POST(cpr::Url{url});

            nlohmann::json j = user;

            auto response = cpr::POST(
                cpr::Url{url},
                 cpr::Body{j.dump}, cpr::Header{{ {"Content-Type", "application/json"} }}, 
                cpr::Timeout{5000}
            );
            if(reponse.status_code != 200) { throw std::runtime_error("rip"); }
            return nlohmann::json::parse(response.text).get<>();
        }
        // Delete user
        // This can only be done by the logged in user.
         deleteUser(std::string username) {
            std::string url = baseUrl + "/user/{username}";
            url = std::regex_replace(url, std::regex("\\{\\{?username\\}\\}"), std::to_string(username));
            auto response = cpr::DELETE(cpr::Url{url});


            auto response = cpr::DELETE(
                cpr::Url{url},
                
                cpr::Timeout{5000}
            );
            if(reponse.status_code != 200) { throw std::runtime_error("rip"); }
            return nlohmann::json::parse(response.text).get<>();
        }
        // Get user by user name
        // 
        std::shared_ptr<User> getUserByName(std::string username) {
            std::string url = baseUrl + "/user/{username}";
            url = std::regex_replace(url, std::regex("\\{\\{?username\\}\\}"), std::to_string(username));
            auto response = cpr::GET(cpr::Url{url});


            auto response = cpr::GET(
                cpr::Url{url},
                
                cpr::Timeout{5000}
            );
            if(reponse.status_code != 200) { throw std::runtime_error("rip"); }
            return nlohmann::json::parse(response.text).get<std::shared_ptr<User>>();
        }
        // Logs user into the system
        // 
        std::string loginUser(std::string username, std::string password) {
            std::string url = baseUrl + "/user/login";
            std::string query;
            query += "username=" + cpr::util::urlEncode(username) + "&";
            query += "password=" + cpr::util::urlEncode(password);
            url += "?" + query;
            auto response = cpr::GET(cpr::Url{url});


            auto response = cpr::GET(
                cpr::Url{url},
                
                cpr::Timeout{5000}
            );
            if(reponse.status_code != 200) { throw std::runtime_error("rip"); }
            return nlohmann::json::parse(response.text).get<std::string>();
        }
        // Logs out current logged in user session
        // 
         logoutUser() {
            std::string url = baseUrl + "/user/logout";
            auto response = cpr::GET(cpr::Url{url});


            auto response = cpr::GET(
                cpr::Url{url},
                
                cpr::Timeout{5000}
            );
            if(reponse.status_code != 200) { throw std::runtime_error("rip"); }
            return nlohmann::json::parse(response.text).get<>();
        }
        // Updated user
        // This can only be done by the logged in user.
         updateUser(std::string username, std::shared_ptr<User> user) {
            std::string url = baseUrl + "/user/{username}";
            url = std::regex_replace(url, std::regex("\\{\\{?username\\}\\}"), std::to_string(username));
            auto response = cpr::PUT(cpr::Url{url});

            nlohmann::json j = user;

            auto response = cpr::PUT(
                cpr::Url{url},
                 cpr::Body{j.dump}, cpr::Header{{ {"Content-Type", "application/json"} }}, 
                cpr::Timeout{5000}
            );
            if(reponse.status_code != 200) { throw std::runtime_error("rip"); }
            return nlohmann::json::parse(response.text).get<>();
        }
private:
    std::string baseUrl;
}
