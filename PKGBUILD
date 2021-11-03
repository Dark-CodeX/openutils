pkgname="sstring"
pkgver="40.0.0"
pkgrel="5"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=(
  "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h"
  "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h"
  "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/binary.h"
  "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/morse_code.h")

sha512sums=(
  "d9c4b2d8f86bbcd13aae0a0e14d8df452dc1860bcde77d46a7c8c23607ce50b7c3661a47f2f94f04802049e4a129b6f0db3b0f7ebfec97d1da3c69712c866612"
  "1fe6d856014c5a8bbf6348d051a0b0cb6f5cf931be57e3b2aa9b1a4b000a9fbf05d14329b359ecd8dd29e90c788c701f5102b7e9d0d4ee04c298c63edcff7108"
  "448807a307f41cac33d9bf249803fe643ceea86a1d4b9556c692e36d16b5b8f1e766cc5a8fdece460ad8c9149724a1bee685f5dec05f5c7ab7fe6c64dbabce8e"
  "2e21374a5f2b875b6fefcb675816ea1605fb5a99458ddb799e1647a724217dda85e8f8ab9136f04db50d11913ee62169b9f1c1f299091f4ce6f957f535b10840")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  cp "${srcdir}/binary.h" "${pkgdir}/usr/include/sstring/binary.h"
  cp "${srcdir}/morse_code.h" "${pkgdir}/usr/include/sstring/morse_code.h"
  echo "Done!"
}
