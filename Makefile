# Makefile for Camera Slider Firmware Documentation

.PHONY: docs clean docs-open help

# Default target
help:
	@echo "Available targets:"
	@echo "  docs      - Generate Doxygen documentation"
	@echo "  docs-open - Generate docs and open in browser"
	@echo "  clean     - Remove generated documentation"
	@echo "  help      - Show this help message"

# Generate documentation
docs:
	@echo "Generating Doxygen documentation..."
	doxygen Doxyfile
	@echo "Documentation generated in docs/html/ directory"

# Generate docs and open in browser
docs-open: docs
	@echo "Opening documentation in browser..."
	@if command -v open >/dev/null 2>&1; then \
		open docs/html/index.html; \
	elif command -v xdg-open >/dev/null 2>&1; then \
		xdg-open docs/html/index.html; \
	else \
		echo "Please open docs/html/index.html in your browser"; \
	fi

# Clean generated files
clean:
	@echo "Cleaning generated documentation..."
	rm -rf docs/
	@echo "Clean complete"

# Install Doxygen if not present (macOS)
install-doxygen:
	@if ! command -v doxygen >/dev/null 2>&1; then \
		echo "Installing Doxygen..."; \
		if command -v brew >/dev/null 2>&1; then \
			brew install doxygen; \
		else \
			echo "Please install Doxygen manually: https://www.doxygen.nl/download.html"; \
		fi \
	else \
		echo "Doxygen is already installed"; \
	fi
