pkgname="openutils-map"
pkgver="1.6.1"
pkgrel="3"
pkgdesc="Memory Safe Map Library in C/C++ language."
arch=("x86_64" "i686")
conflicts=('openutils-map')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/map/master/map/map.hh" "https://raw.githubusercontent.com/Dark-CodeX/map/master/map/map.h" "https://raw.githubusercontent.com/Dark-CodeX/map/master/map/prototype_err.h")

sha512sums=("22ebc1fb08a0ec2b6d099d5e831d1135462a3a083a86165cda11f02aaa4919afc220b89a1a8b4136d2f9680f317da0be9e88aee31371dad50a1e54fa543a9be3" "4b421d8670f8436c29eaa9c2ab68864aa88387426fb3fe89ce733cf49f772eb1ce97615480dcfbba8cff6914dfa60dc35cca3ce82cf398007440b138fc5d5b53" "3b7777430edf1c8533f8bf4614c3e26c817958f3edd15300c0918342f4486d13886f9a15c61616cdfecee26a13cdaa30547c89d25c6e6a91658c29fb2e3ed51e")

package() {
  echo "Memory Safe Map Library in C++ language."
  mkdir -p "${pkgdir}/usr/include/openutils/map"
  cp "${srcdir}/map.hh" "${pkgdir}/usr/include/openutils/map/map.hh"
  cp "${srcdir}/map.h" "${pkgdir}/usr/include/openutils/map/map.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/openutils/map/prototype_err.h"
  echo "Done!"
}
