#ifndef MUUR_HPP
#define MUUR_HPP

#include "window.hpp"
#include "rectangle.hpp"
#include "vector.hpp"

class muur : public rectangle {
private:
	bool filled;
	int update_interval;
	int update_count;
	vector start_help;
	
public:
	muur (window & w, const vector & start, const vector & end, bool filled = 1, int update_interval = 100, int update_count = 0);
	void draw() override;
	void update() override;
};

#endif // MUUR_HPP
