param([switch] $exec, [switch] $main, [switch] $temp, [switch] $a, [switch] $ae)
# exec - executes after building
# main - builds to GuessMyNumber/game.exe
# temp - builds to GuessMyNumber/source/a.exe
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


$SourceFile = [string]::format("{0}\Documents\vscode\cpp\GuessMyNumber\source\main.cpp", $home)
$TempBuildLoc = [string]::format("{0}\Documents\vscode\cpp\GuessMyNumber\source\a.exe", $home)
$MainBuildLoc = [string]::format("{0}\Documents\vscode\cpp\GuessMyNumber\game.exe", $home)

$WaitTime = 1

function Build {
    param($BuildLocation = $null)
    Write-Output "Building GuessMyNumber at $BuildLocation..."
    try {
        if ($BuildLocation -eq $null) { # if parameter not set, build to default location
            g++ $SourceFile
        } else {
            g++ $SourceFile -o $BuildLocation
        }

        Write-Output "Successfully built."
    }
    catch {}
}

if ($main -eq $true) {
    Build $MainBuildLoc
    Write-Output ""
    
    if ($temp -eq $true) {
        Build $TempBuildLoc
    }
} else {
    Build $TempBuildLoc
}

if ($exec -eq $true) {
    Write-Output ""
    Write-Output "Executing application..."
    Start-Sleep -s $WaitTime
    if ($main -eq $true) {
        Invoke-Expression $MainBuildLoc
    } elseif ($temp -eq $true) {
        Invoke-Expression $TempBuildLoc
    }
}
