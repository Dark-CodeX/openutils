pkgname="map"
pkgver="1.5.1"
pkgrel="1"
pkgdesc="Memory Safe Map Library in C++ language."
arch=("x86_64" "i686")
conflicts=('map')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/map/master/map/map.hh")

sha512sums=("b300f5d3fe589e0ba2903956ab09a41135ebc910eae13e45b19e1c0fcc244c39dafdc4fec936abaf60058e7af3cacc014f6ff7887d2a05c7ef07becd00d2a8cf")

package() {
  echo "Memory Safe Map Library in C++ language."
  mkdir -p "${pkgdir}/usr/include/map"
  cp "${srcdir}/map.hh" "${pkgdir}/usr/include/map/map.hh"
  echo "Done!"
}
