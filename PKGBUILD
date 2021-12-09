pkgname="map"
pkgver="1.0.4"
pkgrel="1"
pkgdesc="Memory Safe Map Library in C++ language."
arch=("x86_64" "i686")
conflicts=('map')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/map/master/map/map.hh")

sha512sums=("0f27b309b8e2dba9a70f2aa85fbcba5b626bc4798403fbcfbeafe54a389256bd789b69b2fbbbd20dc2190be39ed260410e05e219be4fdcdb849ea6b66ebf8b4e")

package() {
  echo "Memory Safe Map Library in C++ language."
  mkdir -p "${pkgdir}/usr/include/map"
  cp "${srcdir}/map.hh" "${pkgdir}/usr/include/map/map.hh"
  echo "Done!"
}
