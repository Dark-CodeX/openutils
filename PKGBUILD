pkgname="sstring"
pkgver="5.2.0"
pkgrel="4"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/binary.h")
sha512sums=("76d392a9c4203e7c8b96286548245d96dea27df34807b07edbfe0b19f0f46468ac255a719afb23331ce91f14f8c51b6227c93e99c14718779bf6dbc5a2d3f589" "86ee51606304f606d6e853f6c28f90b218dce9623c9dafe106a72b54caeb35aa4bd9adb01f698dc931782f6bcb09d1c57a84e252e635dfadb988bccda61d3fa4" "f7cfcbe31c29bde2af531077ab81c872f95a15a39d1a61383a2a758184b1c32ff9ffcdedc60ce535359bed343f4ec3803ff5ff43b5c390ff12cf6e18de395653")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  cp "${srcdir}/binary.h" "${pkgdir}/usr/include/sstring/binary.h"
  echo "Done!"
}
