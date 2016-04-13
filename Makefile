.PHONY: clean All

All:
	@echo "----------Building project:[ PxMemTest - Debug ]----------"
	@cd "PxMemTest" && "$(MAKE)" -f  "PxMemTest.mk"
clean:
	@echo "----------Cleaning project:[ PxMemTest - Debug ]----------"
	@cd "PxMemTest" && "$(MAKE)" -f  "PxMemTest.mk" clean
