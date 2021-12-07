pkgname="map"
pkgver="1.0.2"
pkgrel="1"
pkgdesc="Memory Safe Map Library in C++ language."
arch=("x86_64" "i686")
conflicts=('map')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/map/master/map/map.hh")

sha512sums=("8a8727b0182b2649bf9547834d6ddbe22aca43f45e169e307563fda0f8e5198cf5af6287595bab0ae3620d379b9e0e4fb8bb4f9d541c5aa7eaa496fe937287e4")

package() {
  echo "Memory Safe Map Library in C++ language."
  mkdir -p "${pkgdir}/usr/include/map"
  cp "${srcdir}/map.hh" "${pkgdir}/usr/include/map/map.hh"
  echo "Done!"
}
