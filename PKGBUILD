pkgname="sstring"
pkgver="17.1.0"
pkgrel="4"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/binary.h")
sha512sums=("35b3f6e66e237b8cdc3577e497ab6837fd1f0717ef316b002a1d55531a7fe6d6141d207cadd24ec4b08ca2f6968968159ef9e3fa00c7030b5bff185144a3876a" "66be88a4b63312cd1483c84fb7b17f49823d29afff733496662eb423894fa9d93d384333e99d3d3bb3d7364ef483da361ee01ea3e4699015b9d2316baf40bf0c" "279fab44ab469c8b77d0282664363e437f39411af3e9dba23981c67405c2147cd4be98fec4f0b9f63d8cfe7ff9f6af672d360ac7a672ae6c569a7785008074df")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  cp "${srcdir}/binary.h" "${pkgdir}/usr/include/sstring/binary.h"
  echo "Done!"
}
