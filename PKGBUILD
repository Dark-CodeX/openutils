pkgname="sstring"
pkgver="5.0.0"
pkgrel="4"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/binary.h")
sha512sums=("e8c21ac099f067fd232c47e015d132d6a34d84376583fb64139795c46915e30f7561b3492d5fca08af896025bff8bd55c10b9ad15301e0ebe0185100f7338408" "40176970c38e4d25e81278e0aa8762a87afcb03a13474a938a0a100c99f74abd7a0c86c820361b131aeb20f1e2cc21d6106758e3146228e658d4d25411726a73" "8537ae68c6f7bcfce2cdb4124e7a52f13b372a0bc6bdae840bce2155df6b9c98cc1c5d8f61856bad3a4e08f902b6799b5493194410d3f6b6b1c4f082ead113fe")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  cp "${srcdir}/binary.h" "${pkgdir}/usr/include/sstring/binary.h"
  echo "Done!"
}
