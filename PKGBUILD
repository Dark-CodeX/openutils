pkgname="sstring"
pkgver="17.0.0"
pkgrel="4"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/binary.h")
sha512sums=("24769bff7cb509ec818f2b02d4cb551ee2ebb1f1386e06964d249316cfc2901680ba05d02c973be8869ae3018f38e764944f191e38c160d2936da2d0b36d89c1" "41771edf032e74fb71533c5336514edfc93a02d0a628bae11ec42c328452fb32fcdf735672b56597769ea788809ca8dff37b9dd6a2f141bcd53d5cd9f431f996" "9624f7320759949e91000cf45569d8481721e4155174f660684e1a621cabeeba004b849751b6b2a785c36ed5aa89fb761a033f69aaeed080a31bbeb954612065")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  cp "${srcdir}/binary.h" "${pkgdir}/usr/include/sstring/binary.h"
  echo "Done!"
}
