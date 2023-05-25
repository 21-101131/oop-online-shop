#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>
#include <sstream>

using std::vector;
using std::string;

class BaseEntity {
	int id;

public:
	BaseEntity();
	BaseEntity(int, string, vector<string>);
	void setId(int _id);
	int getId() const;

};