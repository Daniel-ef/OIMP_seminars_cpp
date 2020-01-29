struct Order {
	std::string order_id;
	std::vector<double> point_a;
	std::vector<double> point_b;  // maybe empty
};

struct Driver {
	std::string uuid;
	double eta; // estimated time arrival
}

if point_b empty -> skip order and drivers

struct CheckDrivers {
	size_t order_index;
	size_t driver_index;
}
struct Request {
	std::vector<CheckDrivers> check_drivers;  // sorted by eta
}

Request MakeCheckDrivers(
	const std::vector<Order>& orders,
	// Drivers can be duplicated for different orders
	const std::vector<std::vector<Driver>>& drivers 
);

Orders:
[
	{"order1", [1, 2], [3, 4]}
	{"order2", [1, 2], }
	{"order3", [1, 2], [3, 4]}
]

Drivers:
[
	[{"driver1", 57}, {"driver2", 120},
	[{"driver1", 57}],
	[{"driver1", 57}, {"driver3", 10}],
]

Request:
{
	[
		{2, 3}, // order3, driver3
		{1, 1}, // order1, driver1
		{2, 1}, // order3, driver1
		{2, 2}, // order1, driver2
    ] 
}

// Нужно написать генерацию запроса к сервису, 
// который проверяет водителя по некоторому условию.
