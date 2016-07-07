#ifndef VICTIM_HPP
#define	VICTIM_HPP

#include "window.hpp"
#include "rectangle.hpp"
#include "vector.hpp"

class victim : public rectangle {
	
	vector & start;
	vector & end
public:
	victim (window & w, const vector & start, const vector & end);
	void interact(drawable& other) override;
	void update() override;
	
};

#endif // VICTIM_HPP
