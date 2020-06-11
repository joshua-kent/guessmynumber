# Builds the program from source code
# Uses g++ compiler by default, and compiles
# to Windows and Linux as an executable.

param([switch] $exec, [switch] $main, [switch] $temp, [switch] $a, [switch] $ae)

$LinuxCommand = "wsl -e" # executing in WSL
$LinuxConvertPath = "wsl wslpath -a"

$CurrentFile_WIN = $PSScriptRoot
$CurrentFile_WIN_comp = $CurrentFile_WIN.Replace("\", "/")
$CurrentFile_LNX = Invoke-Expression "$LinuxConvertPath $CurrentFile_WIN_comp"
$SourceFile_WIN = [string]::format("{0}\main.cpp", $CurrentFile_WIN)
$SourceFile_LNX = [string]::format("{0}/main.cpp", $CurrentFile_LNX)
$TempBuildLoc_WIN = [string]::format("{0}\a.exe", $CurrentFile_WIN)
$TempBuildLoc_LNX = [string]::format("{0}/a.out", $CurrentFile_LNX)
$MainBuildLoc_WIN = [string]::format("{0}\..\GMN_win64.exe", $CurrentFile_WIN)
$MainBuildLoc_LNX = [string]::format("{0}/../GMN_linux", $CurrentFile_LNX)

$WaitTime = 1
# exec - executes after building
# main - builds to GuessMyNumber/GMN_win64.exe and /GMN_linux
# temp - builds to GuessMyNumber/source/a.exe and /a.out
# a - builds to all locations
# ae - builds to all locations and executes

if ($ae -eq $true) {
    $exec = $true
    $a = $true # executes next part too
}
if ($a -eq $true) {
    $main = $true
    $temp = $true
}

function Build {
    param($BuildLocation = $null, $OS = "win64") # when BuildLocation is null, build to temporary location
    
    if ($BuildLocation -eq $null) {
        if ($OS -eq "win64") {
            $BuildLocation = $TempBuildLoc_WIN
        } elseif ($OS -eq "linux") {
            $BuildLocation = $TempBuildLoc_LNX
        }
    }

    if ($OS -eq "win64") {
        Write-Output "Building GuessMyNumber for Windows 64-bit at $BuildLocation..."
    } elseif ($OS -eq "linux") {
        Write-Output "Building GuessMyNumber for Linux at $BuildLocation..."
    }
    
    try {
        if ($OS -eq "win64") {
            g++ $SourceFile_WIN -o $BuildLocation
        } elseif ($OS -eq "linux") {
            Invoke-Expression "$LinuxCommand g++ $SourceFile_LNX -o $BuildLocation"
        }

        Write-Output "Build complete."
    }
    catch {}
}

if ($main -eq $true) {
    Build $MainBuildLoc_WIN # build to main location for windows
    Write-Output ""
    Build $MainBuildLoc_LNX "linux" # build to main location for linux
    Write-Output ""
    
    if ($temp -eq $true) {
        Build # build to temp location for windows
        Write-Output ""
        Build -OS "linux" # build to temp location for linux
    }
} else {
    Build # build to temp location for windows
    Write-Output ""
    Build -OS "linux" # build to temp location for linux
}

if ($exec -eq $true) {
    Write-Output ""
    Write-Output "Executing application..."

    Start-Sleep -s $WaitTime
    
    if ($main -eq $true) {
        Invoke-Expression $MainBuildLoc_WIN
    } elseif ($temp -eq $true) {
        Invoke-Expression $TempBuildLoc_WIN
    }
}
