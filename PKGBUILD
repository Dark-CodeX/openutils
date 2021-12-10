pkgname="map"
pkgver="1.0.5"
pkgrel="1"
pkgdesc="Memory Safe Map Library in C++ language."
arch=("x86_64" "i686")
conflicts=('map')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/map/master/map/map.hh")

sha512sums=("6cd61593b6131da207ba0a8a5ec322cc0ac27d5be010d616fd57ad4cd6bdbf79ae2be5ddea35c54f8aaf975549f59df4a1bf22c52cebd8478ec4138ba5076c3a")

package() {
  echo "Memory Safe Map Library in C++ language."
  mkdir -p "${pkgdir}/usr/include/map"
  cp "${srcdir}/map.hh" "${pkgdir}/usr/include/map/map.hh"
  echo "Done!"
}
