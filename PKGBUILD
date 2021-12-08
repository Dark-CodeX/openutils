pkgname="map"
pkgver="1.0.3"
pkgrel="1"
pkgdesc="Memory Safe Map Library in C++ language."
arch=("x86_64" "i686")
conflicts=('map')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/map/master/map/map.hh")

sha512sums=("344f070279d1f9c295eaaf3265b2bb770c93691e5edbe3676acbb3289fb4738d94577b69ce6b86e3864b02e7d11193579947dba9012dcbd2442f27a18cc1140c")

package() {
  echo "Memory Safe Map Library in C++ language."
  mkdir -p "${pkgdir}/usr/include/map"
  cp "${srcdir}/map.hh" "${pkgdir}/usr/include/map/map.hh"
  echo "Done!"
}
