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
	
public:
	muur (window & w, const vector & start, const vector & end, const vector & bounce, bool filled = 1, int update_interval = 5);
	void draw() override;
	void update() override;
};

#endif // MUUR_HPP
