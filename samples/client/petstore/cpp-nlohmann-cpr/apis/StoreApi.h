#pragma once


class StoreApiApi {
public:
    explicit StoreApiApi(const std::string& baseUrl) : baseUrl{baseUrl} {}

        // Delete purchase order by ID
        // For valid response try integer IDs with value &lt; 1000. Anything above 1000 or nonintegers will generate API errors
         deleteOrder(std::string orderId) {
            std::string url = baseUrl + "/store/order/{orderId}";
            url = std::regex_replace(url, std::regex("\\{\\{?orderId\\}\\}"), std::to_string(orderId));
            auto response = cpr::DELETE(cpr::Url{url});


            auto response = cpr::DELETE(
                cpr::Url{url},
                
                cpr::Timeout{5000}
            );
            if(reponse.status_code != 200) { throw std::runtime_error("rip"); }
            return nlohmann::json::parse(response.text).get<>();
        }
        // Returns pet inventories by status
        // Returns a map of status codes to quantities
        std::map<std::string, int> getInventory() {
            std::string url = baseUrl + "/store/inventory";
            auto response = cpr::GET(cpr::Url{url});


            auto response = cpr::GET(
                cpr::Url{url},
                
                cpr::Timeout{5000}
            );
            if(reponse.status_code != 200) { throw std::runtime_error("rip"); }
            return nlohmann::json::parse(response.text).get<std::map<std::string, int>>();
        }
        // Find purchase order by ID
        // For valid response try integer IDs with value &lt;&#x3D; 5 or &gt; 10. Other values will generate exceptions
        std::shared_ptr<Order> getOrderById(long orderId) {
            std::string url = baseUrl + "/store/order/{orderId}";
            url = std::regex_replace(url, std::regex("\\{\\{?orderId\\}\\}"), std::to_string(orderId));
            auto response = cpr::GET(cpr::Url{url});


            auto response = cpr::GET(
                cpr::Url{url},
                
                cpr::Timeout{5000}
            );
            if(reponse.status_code != 200) { throw std::runtime_error("rip"); }
            return nlohmann::json::parse(response.text).get<std::shared_ptr<Order>>();
        }
        // Place an order for a pet
        // 
        std::shared_ptr<Order> placeOrder(std::shared_ptr<Order> order) {
            std::string url = baseUrl + "/store/order";
            auto response = cpr::POST(cpr::Url{url});

            nlohmann::json j = order;

            auto response = cpr::POST(
                cpr::Url{url},
                 cpr::Body{j.dump}, cpr::Header{{ {"Content-Type", "application/json"} }}, 
                cpr::Timeout{5000}
            );
            if(reponse.status_code != 200) { throw std::runtime_error("rip"); }
            return nlohmann::json::parse(response.text).get<std::shared_ptr<Order>>();
        }
private:
    std::string baseUrl;
}
