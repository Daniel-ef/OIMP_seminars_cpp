#include <map>
#include <random>
#include <string>
#include <vector>

struct Order {
  std::string order_id;
  std::vector<double> point_a;
  std::vector<double> point_b; // maybe empty
};

struct Driver {
  std::string uuid;
  double eta; // estimated time arrival
};

struct CheckDrivers {
  // Continious indexes starting from 0
  size_t order_index;
  size_t driver_index;
};

struct FilteredDrivers {
  std::vector<Order> orders;
  std::vector<Driver> drivers;
};

using Request = std::vector<CheckDrivers>;
using Response = std::vector<CheckDrivers>; // sorted by eta

bool check_sorted_continious(std::vector<size_t> &vec) {
  std::sort(vec.begin(), vec.end());
  std::vector<size_t> checking(vec.size());
  std::iota(checking.begin(), checking.end(), 0);
  return vec == checking;
}

Response SendRequest(const Request &request) {
  std::map<size_t, std::vector<size_t>> order_idx_drivers_idx;
  std::vector<size_t> order_idxs;
  std::vector<size_t> driver_idxs;
  for (const auto &check_drivers : request) {
    order_idx_drivers_idx[check_drivers.order_index].push_back(
        check_drivers.driver_index);
    order_idxs.push_back(check_drivers.order_index);
    driver_idxs.push_back(check_drivers.driver_index);
  }
  assert(check_sorted_continious(order_idxs));

  Response response(request.size());
  for (const auto &[order_idx, drivers_idx] : order_idx_drivers_idx) {
    if (random() % 2) {
      response.push_back(
          {order_idx, drivers_idx[random() % drivers_idx.size()]});
    }
  }
  return response;
}

FilteredDrivers FilterDrivers(const std::vector<Order> &orders,
                              // Drivers can be duplicated for different orders
                              const std::vector<std::vector<Driver>> &drivers) {
  Request request;
  // Write your code here
  Response response = SendRequest(request);

  FilteredDrivers filtered_drivers;
  // Write your code here
  return filtered_drivers;
}

/*
Orders:
[
  {"order0", [0, 1], [2, 3]}
  {"order1", [0, 1]}
  {"order2", [0, 1], [2, 3]}
]

Drivers:
[
  [{"driver0", 57}, {"driver1", 120}],
  [{"driver0", 57}],
  [{"driver0", 57}, {"driver2", 10}],
]

Request:
[
  {2, 3}, // order2, driver2
  {1, 1}, // order0, driver0
  {2, 1}, // order2, driver0
  {2, 2}, // order0, driver1
]

Response:
{
  [
    {1, 1}, // order0, driver0
    {2, 3}, // order2, driver2
  ]
}

FilteredDrivers:
 Orders:
  [
    {"order0", [1, 2], [3, 4]}
    {"order2", [1, 2], [3, 4]}
  ]

  Drivers:
    [
      {"driver0", 57},
      {"driver2", 10}
    ]

 */

// Нужно написать генерацию запроса к сервису,
// который проверяет водителя по некоторому условию.
