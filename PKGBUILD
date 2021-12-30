pkgname="openutils-map"
pkgver="1.5.2"
pkgrel="2"
pkgdesc="Memory Safe Map Library in C++ language."
arch=("x86_64" "i686")
conflicts=('openutils-map')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/map/master/map/map.hh")

sha512sums=("1dea6dd3136ab38542b0ea75c29af159786187eacd83b99609895c9203ed637685f72ac24cd0d07db59a6b3d72d7aabe79ba22924e7f7560ff43cfb91ab0303e")

package() {
  echo "Memory Safe Map Library in C++ language."
  mkdir -p "${pkgdir}/usr/include/openutils/map"
  cp "${srcdir}/map.hh" "${pkgdir}/usr/include/openutils/map/map.hh"
  echo "Done!"
}
