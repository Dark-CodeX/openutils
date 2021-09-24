pkgname="sstring"
pkgver="10.0.0"
pkgrel="4"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/binary.h")
sha512sums=("934cdacea2b4dfab1a3a05bb77d63e65127046e93ee639a21587d64f0be486fbbd9d70786fd9d2fec7e6aaee45fbaf66aca9eb501d9c799cafa2b379fdf10a71" "2cee2fe9d557dd5275b5d7efd53f9cc77814d601e31ff46964b0302652b792fef3d0fbeffd92e5ab92a55a4944c58758efe87dd3db6adb0adbd1073d12fbf136" "563914d5496934c79e8add4ea238a4f085e9e102d4b1e2ce4c9be23a7f7bfecfa5f9b988e1e4caede07744a24ad255a84a341bdfa166eba7037dd2afb6ba12ef")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  cp "${srcdir}/binary.h" "${pkgdir}/usr/include/sstring/binary.h"
  echo "Done!"
}
