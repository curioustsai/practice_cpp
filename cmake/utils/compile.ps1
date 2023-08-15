param(
  [Parameter(Mandatory)]
  [ValidateSet('Debug', 'Release')]
  [string]$BuildType,

  [Parameter()]
  [Int] $JobNumber = 8,

  [Parameter()]
  [Switch] $CleanAll
)


$ProjectRoot="$PSScriptRoot/../.."
$WorkDir="$ProjectRoot/build/$BuildType"

if ($CleanAll){
  if (Test-Path -Path $WorkDir) {
    Remove-Item -Recurse $WorkDir
  }
}

mkdir -p $WorkDir
Set-Location $WorkDir
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=$BuildType -G Ninja $ProjectRoot
ninja -j $JobNumber
ctest
Set-Location $ProjectRoot
