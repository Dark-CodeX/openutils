pkgname="map"
pkgver="1.0.1"
pkgrel="1"
pkgdesc="Memory Safe Map Library in C++ language."
arch=("x86_64" "i686")
conflicts=('map')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/map/master/map/map.hh")

sha512sums=("414f45ef26aed30625c008edb7bea86d8a8f9f4574a999e438ce21f6d61edae0335e1e2632541a22c4631a0bd783886a68cf9feff825226328bd154eeb5ad747")

package() {
  echo "Memory Safe Map Library in C++ language."
  mkdir -p "${pkgdir}/usr/include/map"
  cp "${srcdir}/map.hh" "${pkgdir}/usr/include/map/map.hh"
  echo "Done!"
}
