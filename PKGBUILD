pkgname="sstring"
pkgver="7.7.3"
pkgrel="4"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/binary.h")
sha512sums=("7e2fe9a3192fe90f7328684fb6dd6990d367a601d0a75b28be7478fdbc44e1d4ddcd10737901bd4c623e5ec55de89abe759827d3cbab11813f76d86bf57a78d2" "792138490a61c1ef128316725b0ba884ec905f89e3a6079c8fc045e493c2d9471132397ea0f3a820db5e3805b64a21823f2083bda4ec41f9af2a7fc076f39c18" "a35bcae576e128c82f6730a4842a4daaee5821e0886b396d6226d779f5f0325c3a4de58e97b88c66728c409f6b60c055edeac39c1d40b2ec919777fb13cb567f")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  cp "${srcdir}/binary.h" "${pkgdir}/usr/include/sstring/binary.h"
  echo "Done!"
}
