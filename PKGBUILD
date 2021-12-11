pkgname="map"
pkgver="1.5.0"
pkgrel="1"
pkgdesc="Memory Safe Map Library in C++ language."
arch=("x86_64" "i686")
conflicts=('map')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/map/master/map/map.hh")

sha512sums=("79e67066239759cb8734ca30df1141f57156c69a086c48c5c4a4533d2910dd243f391071e54598e80320a96f8be614181e8aefadccf7b26a2cc55c7d928d8428")

package() {
  echo "Memory Safe Map Library in C++ language."
  mkdir -p "${pkgdir}/usr/include/map"
  cp "${srcdir}/map.hh" "${pkgdir}/usr/include/map/map.hh"
  echo "Done!"
}
