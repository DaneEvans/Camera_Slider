# Camera Slider Firmware Documentation

This directory contains the auto-generated documentation for the Camera Slider firmware project.

## Generating Documentation

### Prerequisites

1. Install Doxygen:
   ```bash
   # On macOS with Homebrew
   brew install doxygen
   
   # On Ubuntu/Debian
   sudo apt-get install doxygen
   
   # On Windows, download from https://www.doxygen.nl/download.html
   ```

2. Or use the provided Makefile to install Doxygen:
   ```bash
   make install-doxygen
   ```

### Using the Makefile

The project includes a Makefile with convenient targets for documentation generation:

```bash
# Generate documentation
make docs

# Generate docs and open in browser
make docs-open

# Clean generated files
make clean

# Show help
make help
```

### Manual Generation

If you prefer to run Doxygen manually:

```bash
doxygen Doxyfile
```

## Documentation Structure

The generated documentation includes:

- **HTML Output**: Located in `docs/html/` - open `index.html` in your browser
- **Source Code**: All source files with syntax highlighting
- **Function Documentation**: Auto-generated from function signatures
- **File Dependencies**: Graphs showing include relationships
- **Call Graphs**: Function call relationships (if enabled)

## Configuration

The `Doxyfile` is configured to:

- Include all files in `src/`, `include/`, and `lib/` directories
- Automatically detect new files added to these directories
- Generate HTML documentation with source browsing
- Include dependency graphs and class diagrams
- Support C, C++, and Arduino (.ino) files

## Adding New Files

Simply add new source files to the `src/` directory - they will automatically be included in the next documentation generation.

## Customization

To modify the documentation generation:

1. Edit `Doxyfile` to change settings
2. Add Doxygen comments to your source code for better documentation
3. Modify the Makefile targets as needed

## Troubleshooting

- **Doxygen not found**: Run `make install-doxygen` or install manually
- **Empty documentation**: Ensure your source files are in the configured input directories
- **Build errors**: Check that all dependencies are installed and paths are correct
