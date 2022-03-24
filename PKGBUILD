pkgname="openutils-vector"
pkgver="1.5.6"
pkgrel="4"
pkgdesc="Vectors in C language."
arch=("x86_64" "i686")
conflicts=('openutils-vector')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.h" "https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.hh")
sha512sums=("bb199f23b9c544a1e92310206dcba1ac6c6523765c38081dc50862536ea4c35c60b9b7d96115656d0e3aa62a58ccdc37b821a017603bd035382f317b644ab9aa" "678189643a006f484af91ae1b4cf830940b2d04e9b8f2f34b201fb806ad8f97fd24185c37e27c4dca4f50e632daa93f5936601090ef79a9d513627160ab45276")

package() {
  echo "Vectors in C language."
  mkdir -p "${pkgdir}/usr/include/openutils/vector"
  cp "${srcdir}/vector.h" "${pkgdir}/usr/include/openutils/vector/vector.h"
  cp "${srcdir}/vector.hh" "${pkgdir}/usr/include/openutils/vector/vector.hh"
  echo "Done!"
}