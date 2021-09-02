pkgname="sstring"
pkgver="3.1.1"
pkgrel="2"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h")
sha512sums=("d7205f7145fd7836209b8a56718d9954b7f613eca391dff9b40ea4ac6107f79c57675198fc26e10adc7e899b5d2a079387f3d039a947bdb9c8aa5600515029b8")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  echo "Done!"
}
