DRAFT := draft
UNIT := unit
INTEGRATION := integration
E2E := e2e

test:
	@make -C $(TYPE) test
	@make -C $(TYPE) run

clean:
	@make -C $(DRAFT) clean
	@make -C $(UNIT) clean
	@make -C $(INTEGRATION) clean
	@make -C $(E2E) clean

fclean: clean
	@make -C $(DRAFT) fclean
	@make -C $(UNIT) fclean
	@make -C $(INTEGRATION) fclean
	@make -C $(E2E) fclean

.PHONY: draft unit integration e2e