pkgname="sstring"
pkgver="8.2.0"
pkgrel="4"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/binary.h")
sha512sums=("a3ea4b3a88fe1106d4dd92ac694b23a5fe12bf3fac22735a2cbac974dbfe19d71f7c63e87f549f3d6ab9186c2299baf7e0523fbef982e787957542f0fbe54f05" "15d8cbe008f0205d0f2f469d7e31e1cce0a63af88c4bc58d8b02e49f90026c4794de056e566465494edd2135394920068fc016e8ea5079f7674ba13964931313" "278890ab3942a6c26e4422fbefd31e3170f30b54efe2d9e31a47ad86aa6329523f468c02a49daedee82f433fc7fa5f4f29e709232d702cc4eeda96747394d81d")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  cp "${srcdir}/binary.h" "${pkgdir}/usr/include/sstring/binary.h"
  echo "Done!"
}
