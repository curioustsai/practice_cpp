# usage: .\cmake\utils\compile.ps1 -BuildType Debug  

param(
  # [Parameter(Mandatory)]
  # [ValidateSet('Debug', 'Release')]
  # [string]$BuildType,

  [Parameter()]
  [Switch] $CleanAll
)


$ProjectRoot="$PSScriptRoot/../.."
$WorkDir="$ProjectRoot/build/Debug"

if ($CleanAll){
  if (Test-Path -Path $WorkDir) {
    Remove-Item -Recurse $WorkDir
  }
}

if (!(Test-Path -Path $WorkDir)) {
    mkdir -p $WorkDir
}

Set-Location $WorkDir
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=Debug -G Ninja $ProjectRoot
ninja
ctest
Set-Location $ProjectRoot
