pkgname="vector"
pkgver="24.0.0"
pkgrel="3"
pkgdesc="Vectors in C language."
arch=("x86_64" "i686")
conflicts=('vector')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.h" "https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.hh")
sha512sums=("0a360f589aa70b6f9057ab92d486eb8acf00842f494969d35ec90aff8489077a1912413fe66ea45c0a4fc4fb9255327c7848ffb4c14f184e42a72e8129a6186c" "1868874b7465539db1a745f98f2bbea28c9fc1363d32322ffac7dafa2add4dfb666199e465062c7c5fbf6fc0d2c19bed5069e94c4ed199838d0bff0d0e76e64d")

package() {
  echo "Vectors in C language."
  mkdir -p "${pkgdir}/usr/include/vector"
  cp "${srcdir}/vector.h" "${pkgdir}/usr/include/vector/vector.h"
  cp "${srcdir}/vector.hh" "${pkgdir}/usr/include/vector/vector.hh"
  echo "Done!"
}