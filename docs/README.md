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

### Generating Docs 

If you prefer to run Doxygen manually:

```bash
doxygen Doxyfile
```

## Viewing docs 

- Develop -  `open docs/html/index.html`
- Releases - `on github pages`

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
- Generate HTML documentation with source browsing
- Include dependency graphs and class diagrams
- Support C, C++, and Arduino (.ino) files
