# This program is designed to run on Windows,
# but also creates a Linux version by utilising
# Windows Subsystem for Linux when compiling.

# Builds the program from source code
# Uses g++ compiler by default (edit Build
# function to change), and compiles
# to Windows and Linux as an executable.

param([switch] $exec, [switch] $e)
# exec - executes after building (-e)

$LinuxCommand = "wsl -e" # executing in WSL

$SourceFile_WIN = "source\main.cpp"
$SourceFile_LNX = $SourceFile_WIN.Replace("\", "/")
$BuildLoc_WIN = "GMN_win64.exe"
$BuildLoc_LNX = "GMN_linux"

$WaitTime = 1000 # wait time when executing in milliseconds

if ($e -eq $true) {
    $exec = $true # -e is shorthand for -exec
}

# Function to call when building:
function Build {
    param($BuildLocation = $null, $OS = "win64") # when BuildLocation is null, build to temporary location
    
    if ($BuildLocation -eq $null) {
        if ($OS -eq "win64") {
            $BuildLocation = $BuildLoc_WIN
        } elseif ($OS -eq "linux") {
            $BuildLocation = $BuildLoc_LNX
        }
    }

    if ($OS -eq "win64") {
        Write-Output "Building GuessMyNumber for Windows 64-bit at $BuildLocation..."
    } elseif ($OS -eq "linux") {
        Write-Output "Building GuessMyNumber for Linux at $BuildLocation..."
    }
    
    # TO USE ANOTHER COMPILER, EDIT THE CONTENTS OF THESE IF STATEMENTS
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

# MAIN BUILD:
Build $BuildLoc_WIN # build to main location for windows
Write-Output ""
Build $BuildLoc_LNX "linux" # build to main location for linux
Write-Output ""

# EXECUTE:
if ($exec -eq $true) {
    Write-Output ""
    Write-Output "Executing application..."

    Start-Sleep -millisecond $WaitTime
    
    Invoke-Expression ".\$BuildLoc_WIN"
}
