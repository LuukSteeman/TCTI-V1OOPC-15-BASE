.PHONY: clean All

All:
	@echo "----------Building project:[ 13.2-catch -  ]----------"
	@cd "13.2-catch" && "$(MAKE)" -f  "13.2-catch.mk"
clean:
	@echo "----------Cleaning project:[ 13.2-catch -  ]----------"
	@cd "13.2-catch" && "$(MAKE)" -f  "13.2-catch.mk" clean
