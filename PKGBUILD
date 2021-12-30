pkgname="openutils-map"
pkgver="1.5.3"
pkgrel="2"
pkgdesc="Memory Safe Map Library in C++ language."
arch=("x86_64" "i686")
conflicts=('openutils-map')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/map/master/map/map.hh")

sha512sums=("e18c24c49469c9ce608260671c8902a1e284b297628b530dcbac4028592713137b1432c2ae0057069c271ebce6f7485856e71c5c091e359c3803ec124c976fc9")

package() {
  echo "Memory Safe Map Library in C++ language."
  mkdir -p "${pkgdir}/usr/include/openutils/map"
  cp "${srcdir}/map.hh" "${pkgdir}/usr/include/openutils/map/map.hh"
  echo "Done!"
}
