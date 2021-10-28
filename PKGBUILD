pkgname="sstring"
pkgver="34.1.0"
pkgrel="5"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/binary.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/morse_code.h")

sha512sums=("eea79c1ad6445882bb9be11daae41474f9f9d99475720762675507de425b96e286ab1abd7784686b6e7ca87a53d3571addec6c736b9c1a1815ed6093cb87d2e0" "2883413884fb3ffab338793b29a8d75b47a1142906c9c5f669811312b442f9daf9d2e8ce86254a3f1bfab99c35d8314514287c7fe3326b3f47b917d30506dfaf" "a3d87875fe3cf06ec6a27dc69409f4c8a894289d96eaba55b45ee749d1bb3aeec17614aec7aa6aeffeb89f61dc31820904a1140945824696811a2ad4b3c52244" "a4b620a33f858719265c110fe5633cfc106faa1b6664d590dbd5925e8547f8b4531f80635b0578a147520b6275caa8ef4f3a939cab62a66dc77d12017ada8836")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  cp "${srcdir}/binary.h" "${pkgdir}/usr/include/sstring/binary.h"
  cp "${srcdir}/morse_code.h" "${pkgdir}/usr/include/sstring/morse_code.h"
  echo "Done!"
}
