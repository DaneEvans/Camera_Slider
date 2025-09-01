# Trunk Linting & Formatting Setup

This project uses [Trunk](https://trunk.io/) for consistent code quality, linting, and formatting across multiple languages.

## What is Trunk?

Trunk is a unified developer experience for linting, formatting, and security scanning. It supports multiple languages and tools in a single configuration:

- **C/C++**: clang-format, clang-tidy, cppcheck, cpplint
- **Python**: black, isort, flake8, mypy, ruff
- **JavaScript/TypeScript**: prettier, eslint
- **Shell**: shellcheck
- **YAML**: yamllint, yamlfmt
- **Markdown**: markdownlint

## Quick Start

### 1. Install Trunk

```bash
# macOS
# NOTE: The Homebrew package 'trunk' may not be the official Trunk (trunk.io) CLI.
# For the official Trunk CLI, use the install script:
curl -fsSL https://get.trunk.io | bash
# Or see https://trunk.io/docs/install for details.

# Linux
curl -fsSL https://get.trunk.io | bash

# Windows
# Download from https://trunk.io/
```

### 2. Install Pre-commit Hooks (Optional)

```bash
# Install pre-commit
pip install pre-commit

# Install the git hook scripts
pre-commit install
```

### 3. Run Trunk

```bash
# Check all files
trunk check

# Format all files
trunk fmt

# Check specific files
trunk check src/motors.cpp

# Format specific files
trunk fmt include/ble_api.h
```

## Configuration

### Trunk Configuration (`.trunk/trunk.yaml`)

The main configuration file defines:

- **Linters**: Which tools to use for code quality checks
- **Formatters**: Which tools to use for code formatting
- **Ignore patterns**: Files and directories to exclude
- **Runtime versions**: Specific versions of Node.js, Python, Rust

### Ignore Patterns (`.trunkignore`)

Excludes files from trunk processing:

- Documentation files (`docs/`, `*.md`)
- Build artifacts (`lib/`, `build/`)
- Configuration files (`Doxyfile`, `Makefile`)
- Arduino files (`*.ino` - not supported by trunk)

## CI/CD Integration

### GitHub Actions (`.github/workflows/trunk-lint.yml`)

Automatically runs trunk checks on:

- **Push** to main/develop branches
- **Pull requests** to main/develop branches
- **Manual trigger** via workflow_dispatch

The workflow:

1. Sets up trunk with the specified version
2. Caches trunk dependencies for faster runs
3. Runs linting checks (`trunk check --ci`)
4. Verifies formatting (`trunk fmt --check`)
5. Uploads results for review

### Pre-commit Hooks (`.pre-commit-config.yaml`)

Local development hooks that:

- Run trunk checks before each commit
- Ensure code quality standards are met
- Prevent committing code with issues

## Supported Languages & Tools

### C/C++ (Primary)

- **clang-format**: Code formatting
- **clang-tidy**: Static analysis
- **cppcheck**: Error detection
- **cpplint**: Google C++ style guide
- **include-what-you-use**: Header optimization
- **oclint**: Static analysis

### Python

- **black**: Code formatting
- **isort**: Import sorting
- **flake8**: Style guide enforcement
- **mypy**: Type checking
- **ruff**: Fast Python linter

### JavaScript/TypeScript

- **prettier**: Code formatting
- **eslint**: Code quality and style

### Other

- **shellcheck**: Shell script analysis
- **yamllint**: YAML validation
- **yamlfmt**: YAML formatting
- **markdownlint**: Markdown validation

## Usage Examples

### Check Code Quality

```bash
# Check all files
trunk check

# Check specific file types
trunk check --file-pattern "*.cpp"

# Check with specific linters
trunk check --linters clang-format,clang-tidy
```

### Format Code

```bash
# Format all files
trunk fmt

# Format specific files
trunk fmt src/*.cpp include/*.h

# Check formatting without changing files
trunk fmt --check
```

### View Issues

```bash
# Show all issues
trunk check --output-format=github

# Show issues for specific file
trunk check src/motors.cpp --output-format=github
```

## Customization

### Adding New Linters

Edit `.trunk/trunk.yaml`:

```yaml
lint:
  enabled:
    - your-linter-name
  # Add configuration if needed
  definitions:
    - name: your-linter-name
      files: ["**/*.your-ext"]
      commands:
        - name: lint
          output: format
          args: ["--check", "{target}"]
```

### Excluding Files

Add patterns to `.trunkignore`:

```bash
# Exclude specific files
specific-file.cpp

# Exclude patterns
*.generated.cpp
temp/
```

### Language-Specific Settings

Create language-specific configuration files:

```bash
# Python
pyproject.toml
# or
setup.cfg

# C/C++
.clang-format
.clang-tidy

# JavaScript
.prettierrc
.eslintrc
```

## Troubleshooting

### Common Issues

1. **Trunk not found**: Ensure trunk is installed and in PATH
2. **Linter errors**: Check if required tools are installed
3. **Format conflicts**: Resolve conflicts between different formatters
4. **Performance**: Use `.trunkignore` to exclude large directories

### Getting Help

```bash
# Show trunk help
trunk --help

# Show specific command help
trunk check --help
trunk fmt --help

# Show version
trunk --version

# Show configuration
trunk show-config
```

## Best Practices

1. **Run trunk locally** before committing
2. **Use pre-commit hooks** for automatic checks
3. **Review CI results** for any issues
4. **Keep configuration updated** with project needs
5. **Exclude generated files** to improve performance

## Integration with Existing Tools

### PlatformIO

- Trunk works alongside PlatformIO
- Excludes `.pio/` directory
- Can lint/format source files

### Doxygen

- Excludes `docs/` directory
- Can format header files
- No conflicts with documentation generation

### Git

- Pre-commit hooks integrate with git workflow
- CI runs on push/PR
- Results uploaded for review

## Next Steps

1. **Install trunk** on your development machine
2. **Run initial check** to see current issues
3. **Fix any found issues** and format code
4. **Set up pre-commit hooks** for local development
5. **Review CI results** on your next push/PR

Trunk will help maintain consistent code quality across your Camera Slider firmware project! 🚀
