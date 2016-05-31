#ifndef VICTIM_HPP
#define	VICTIM_HPP

#include "window.hpp"
#include "rectangle.hpp"
#include "vector.hpp"

class victim : public rectangle {
	
public:
	vector start_help;
	victim (window & w, const vector & start, const vector & end);
	void interact(drawable& other) override;
	
};

#endif // VICTIM_HPP
