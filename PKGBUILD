pkgname="sstring"
pkgver="7.5.0"
pkgrel="4"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/binary.h")
sha512sums=("91a477746b78715ff9bfa6776aa74afc366344988e305ae7bb350aa85872ce7fbf7e436918ac0741b91a61d58140384bc9120c77af675c23772f636b28b7e06d" "6987b9bc044a8b7dc4f468a0950545d6cf51658f76f36c130c4e4a1165af9208dc5c33bf900a9af651f9d0f787d1ef65a2775e206ce15fb5fda01f4635afccb1" "ca6984d233f1f2fd3786af40dde34382a8c3d6176a9d5209cd5c3c7fba851c9709897a0da83c5befef5a49103053189ade4f7d5a9d9bc1c57dc31a9e701fec93")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  cp "${srcdir}/binary.h" "${pkgdir}/usr/include/sstring/binary.h"
  echo "Done!"
}
