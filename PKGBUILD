pkgname="openutils-map"
pkgver="1.6.1"
pkgrel="3"
pkgdesc="Memory Safe Map Library in C/C++ language."
arch=("x86_64" "i686")
conflicts=('openutils-map')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/map/master/map/map.hh" "https://raw.githubusercontent.com/Dark-CodeX/map/master/map/map.h" "https://raw.githubusercontent.com/Dark-CodeX/map/master/map/prototype_err.h")

sha512sums=("bcfe803c0b0504f0ba9f5f3296994987dfdedf00e3a16519aabcd9308b20cf138766480b04ad1d903b3941df1bdaf14dd78a8db015b99a74b67b3ef483dc2c18" "4b421d8670f8436c29eaa9c2ab68864aa88387426fb3fe89ce733cf49f772eb1ce97615480dcfbba8cff6914dfa60dc35cca3ce82cf398007440b138fc5d5b53" "3b7777430edf1c8533f8bf4614c3e26c817958f3edd15300c0918342f4486d13886f9a15c61616cdfecee26a13cdaa30547c89d25c6e6a91658c29fb2e3ed51e")

package() {
  echo "Memory Safe Map Library in C++ language."
  mkdir -p "${pkgdir}/usr/include/openutils/map"
  cp "${srcdir}/map.hh" "${pkgdir}/usr/include/openutils/map/map.hh"
  cp "${srcdir}/map.h" "${pkgdir}/usr/include/openutils/map/map.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/openutils/map/prototype_err.h"
  echo "Done!"
}
