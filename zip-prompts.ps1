<#
.SYNOPSIS
    Zips Markdown (.md) files based on specified parameters.

.DESCRIPTION
    This script zips Markdown (.md) files in the current directory and its subdirectories based on the selected option.

.PARAMETER all
    Zip all .md files in the current directory and subdirectories.

.PARAMETER latest
    Zip .md files modified after the latest 'prompts*.zip' file.

.PARAMETER help
    Display script usage and parameter descriptions.
#>

param (
    [switch]$all,
    [switch]$latest,
    [switch]$help
)

$zipname = "prompts_$(Get-Date -Format yyyyMMdd_HHmmss).zip"

function Get-LatestZipDate {
    $latestZip = Get-ChildItem -Path . -Filter "prompts*.zip" | Sort-Object LastWriteTime -Descending | Select-Object -First 1
    if ($null -ne $latestZip) {
        return $latestZip.LastWriteTime
    } else {
        return $null
    }
}

function Show-Help {
    Write-Host "Usage: .\zip_md_files.ps1 [-all] [-latest] [-help]"
    Write-Host "Options:"
    Write-Host "  -all    : Zip all .md files in the current directory and subdirectories."
    Write-Host "  -latest : Zip .md files modified after the latest 'prompts*.zip' file."
    Write-Host "  -help   : Display this help message and exit."
    Write-Host ""
    Write-Host "This script zips Markdown (.md) files based on the selected option."
}

if ($help) {
    Show-Help
} elseif ($all) {
    Write-Host "Zipping all .md files."
    Get-ChildItem -Recurse -Filter "*.md" | Compress-Archive -DestinationPath $zipname -Force
} elseif ($latest) {
    $latestZipDate = Get-LatestZipDate
    if ($null -ne $latestZipDate) {
        Write-Host "Zipping .md files newer than the latest 'prompts*.zip' ($latestZipDate)."
        Get-ChildItem -Recurse -Filter "*.md" | Where-Object { $_.LastWriteTime -gt $latestZipDate } | Compress-Archive -DestinationPath $zipname -Force
    } else {
        Write-Host "No 'prompts*.zip' file found. No .md files zipped."
    }
} else {
    Write-Host "Invalid option. Use -help for usage information."
    exit 1
}
