# GitHub Pages Setup Guide

This guide will help you set up automatic documentation deployment to GitHub Pages using the provided CI workflows.

## Prerequisites

1. **Repository Settings**: Ensure your repository has GitHub Pages enabled
2. **Branch Protection**: Set up branch protection rules for `main` or `master` branch
3. **GitHub Actions**: Actions should be enabled in your repository

## Step 1: Enable GitHub Pages

1. Go to your repository on GitHub
2. Click **Settings** tab
3. Scroll down to **Pages** section (left sidebar)
4. Under **Source**, select **GitHub Actions**
5. Click **Save**

## Step 2: Configure Branch Protection (Recommended)

1. In **Settings** → **Branches**
2. Click **Add rule** for your main branch (`main` or `master`)
3. Enable **Require a pull request before merging**
4. Enable **Require status checks to pass before merging**
5. Search for and select the status checks:
   - `build-firmware` (from CI workflow)
   - `generate-docs` (from CI workflow)
6. Click **Create**

## Step 3: Verify Workflow Files

Ensure these workflow files are in your `.github/workflows/` directory:

- `ci.yml` - Comprehensive CI pipeline
- `pages.yml` - Dedicated documentation deployment
- `docs.yml` - Documentation-only workflow
- `build.yml` - Firmware building workflow

## Step 4: First Deployment

1. **Push to main branch**: The workflows will automatically trigger
2. **Monitor Actions**: Go to **Actions** tab to watch the progress
3. **Check Pages**: Once deployed, your docs will be available at:
   ```
   https://[username].github.io/[repository-name]/
   ```

## Workflow Descriptions

### `ci.yml` - Main CI Pipeline
- **build-firmware**: Compiles firmware using PlatformIO
- **generate-docs**: Creates Doxygen documentation
- **deploy-docs**: Deploys to GitHub Pages (main branch only)
- **test-docs**: Validates generated documentation

### `pages.yml` - Documentation Deployment
- Standalone workflow for documentation deployment
- Can be triggered manually or on push to main
- Includes validation and status reporting

### `build.yml` - Firmware Building
- Focuses on firmware compilation and testing
- Includes PlatformIO cache for faster builds
- Uploads build artifacts for download

## Monitoring and Troubleshooting

### Check Workflow Status
1. Go to **Actions** tab in your repository
2. Click on the workflow name to see detailed logs
3. Green checkmark = success, red X = failure

### Common Issues

#### Documentation Not Deploying
- Check if GitHub Pages is enabled
- Verify workflow permissions in repository settings
- Look for errors in the Actions logs

#### Build Failures
- Check PlatformIO configuration
- Verify all dependencies are available
- Check for syntax errors in source code

#### Permission Errors
- Ensure repository has proper permissions
- Check if workflows have required permissions
- Verify GitHub Pages environment is configured

### Manual Trigger

You can manually trigger workflows:
1. Go to **Actions** tab
2. Select the workflow you want to run
3. Click **Run workflow**
4. Select branch and click **Run workflow**

## Customization

### Modify Workflow Triggers
Edit the `on:` section in any workflow file:
```yaml
on:
  push:
    branches: [ main, develop ]  # Add more branches
  pull_request:
    branches: [ main ]
  schedule:
    - cron: '0 0 * * 0'  # Weekly on Sunday
```

### Add More Environments
To build for different boards, add to `platformio.ini`:
```ini
[env:other_board]
platform = ...
board = ...
framework = arduino
```

### Custom Documentation Settings
Modify `Doxyfile` to change:
- Output formats (HTML, LaTeX, etc.)
- Graph generation options
- File inclusion patterns

## Security Considerations

- **Secrets**: Store sensitive data in repository secrets
- **Permissions**: Use minimal required permissions
- **Dependencies**: Pin action versions for security
- **Branch Protection**: Prevent direct pushes to main branch

## Performance Optimization

- **Caching**: PlatformIO packages are cached between runs
- **Parallel Jobs**: Multiple jobs run simultaneously
- **Artifact Sharing**: Documentation artifacts shared between jobs
- **Conditional Deployment**: Only deploy on main branch pushes

## Support

If you encounter issues:
1. Check the Actions logs for error messages
2. Verify all prerequisites are met
3. Check GitHub's status page for service issues
4. Review workflow syntax in GitHub's documentation
