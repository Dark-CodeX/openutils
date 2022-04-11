pkgname="openutils-map"
pkgver="1.6.2"
pkgrel="3"
pkgdesc="Memory Safe Map Library in C/C++ language."
arch=("x86_64" "i686")
conflicts=('openutils-map')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/map/master/map/map.hh" "https://raw.githubusercontent.com/Dark-CodeX/map/master/map/map.h" "https://raw.githubusercontent.com/Dark-CodeX/map/master/map/prototype_err.h")

sha512sums=("f75058c28e073d4ad7e5088f2f2b7c86eb2bf1349297d003e06859e527ede12b1aa46b78f73fcbe62b1151dc3bc3ca7369f5c966446432ea0d57522f2d79bf9b" "cabb4eb52e773f3b41141cfcc67cdf76580b07691616340aee123d1f54a81616eac150ea4dbd792c9ff7dd87aed78af8ed17f0843ee06f9e087883c7c5eda6dc" "3403b9173b9124d89eab9ca7dfc6204ea68b0f034e6b7398dc1c694b0abcc0e0dae645036d71883bbf5ad3aa18dea4e10e3949364d0c490ba42edd09631ada05")

package() {
  echo "Memory Safe Map Library in C++ language."
  mkdir -p "${pkgdir}/usr/include/openutils/map"
  cp "${srcdir}/map.hh" "${pkgdir}/usr/include/openutils/map/map.hh"
  cp "${srcdir}/map.h" "${pkgdir}/usr/include/openutils/map/map.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/openutils/map/prototype_err.h"
  echo "Done!"
}
