pkgname="openutils-vector"
pkgver="1.5.7"
pkgrel="4"
pkgdesc="Vectors in C language."
arch=("x86_64" "i686")
conflicts=('openutils-vector')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.h" "https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.hh")
sha512sums=("7faee4468fedbc8cdfb29fcd3686b566e8dbd1dea48d76b82579167f484aaa26d081e28af32ea7f828befb6211267287271fded85ec7d440b9cb288839801498" "5f744541d317a5caab538451aacb5eee7390d011f988077dd816b68acf4db005ef60af61e25027cc7866da56cc8ee7c522ad288f0e232d137ec2f538d87fbc4f")

package() {
  echo "Vectors in C language."
  mkdir -p "${pkgdir}/usr/include/openutils/vector"
  cp "${srcdir}/vector.h" "${pkgdir}/usr/include/openutils/vector/vector.h"
  cp "${srcdir}/vector.hh" "${pkgdir}/usr/include/openutils/vector/vector.hh"
  echo "Done!"
}