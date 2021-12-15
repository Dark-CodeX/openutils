pkgname="openutils-map"
pkgver="1.5.1"
pkgrel="2"
pkgdesc="Memory Safe Map Library in C++ language."
arch=("x86_64" "i686")
conflicts=('openutils-map')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/map/master/map/map.hh")

sha512sums=("1a7dfdeb4c6c6a2bab55daee4346e296126131d4ce045ff217dccc774a14e1d169580a998062dc1db921d04fc8059bcb9132d9df854208bed8991e414d09a9fd")

package() {
  echo "Memory Safe Map Library in C++ language."
  mkdir -p "${pkgdir}/usr/include/openutils/map"
  cp "${srcdir}/map.hh" "${pkgdir}/usr/include/openutils/map/map.hh"
  echo "Done!"
}
