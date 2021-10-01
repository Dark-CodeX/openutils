pkgname="vector"
pkgver="5.0.0"
pkgrel="1"
pkgdesc="Vectors in C language."
arch=("x86_64" "i686")
conflicts=('vector')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.h" "https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/prototype_err.h")
sha512sums=("cc71352125ff0e7d231b414c1a71c4b7797f1bc00072b90f2575a89d9cdb3d2744addbb6742b46c869a2506af368ebe00459f4dcfbe3f4f8f55cfc62884fd7f0" "e12d8144483702c7d663705158133762d82f0f26df4130e81d139ea65747607e7c907d97b692c285668bb7afee5c9a675078417f72c2423f9ee9bb9f41cb04f3")

package() {
  echo "Vectors in C language."
  mkdir -p "${pkgdir}/usr/include/vector"
  cp "${srcdir}/vector.h" "${pkgdir}/usr/include/vector/vector.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/vector/prototype_err.h"
  echo "Done!"
}