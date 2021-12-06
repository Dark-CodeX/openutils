pkgname="map"
pkgver="1.0.0"
pkgrel="1"
pkgdesc="Memory Safe Map Library in C++ language."
arch=("x86_64" "i686")
conflicts=('map')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/map/master/map/map.hh")

sha512sums=("fd1dbc2cc1c63533824d4228cde494fc79ad59e6f1267b7f39bc29ec5c1fb5c669bd6c811a5d4e0846867317fdfe271d411b393353f10ea669491852854e6b6a")

package() {
  echo "Memory Safe Map Library in C++ language."
  mkdir -p "${pkgdir}/usr/include/map"
  cp "${srcdir}/map.hh" "${pkgdir}/usr/include/map/map.hh"
  echo "Done!"
}
